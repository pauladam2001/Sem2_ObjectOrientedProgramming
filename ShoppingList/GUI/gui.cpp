//
// Created by paula on 5/21/2021.
//

#include "gui.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QHBoxLayout>

GUI::GUI(Service &service):service{service} {
    this->init_GUI();
    this->populate_list();
    this->connectSignalsAndSlots();
}

GUI::~GUI() {

}

void GUI::init_GUI() {
    QFont font("Helvetica", 10, QFont::Bold);
    this->setWindowTitle("Shopping list");

    this->shoppingListWidget = new QListWidget{};
    this->shoppingListWidget->setFont(font);
    this->deleteButton = new QPushButton{"Delete item"};
    this->deleteButton->setFont(font);
    this->filterButton = new QPushButton{"Filter"};
    this->filterButton->setFont(font);
    this->categoryEdit = new QLineEdit{};
    this->categoryEdit->setFont(font);

    QVBoxLayout* mainLayout = new QVBoxLayout{};  //QHBoxLayout* mainLayout = new QHBoxLayout{};
    mainLayout->addWidget(this->shoppingListWidget);
    mainLayout->addWidget(this->deleteButton);

    QGridLayout* filterLayout = new QGridLayout{};
    filterLayout->addWidget(this->filterButton, 0, 0);
    filterLayout->addWidget(this->categoryEdit, 0, 1);

    mainLayout->addLayout(filterLayout);

    setLayout(mainLayout);
}

void GUI::populate_list() {
    this->shoppingListWidget->clear();
    vector<Item> data = this->service.getData();

    for (auto &element : data)
        this->shoppingListWidget->addItem(QString::fromStdString(element.getCategory() + " | " + element.getName() + " | ") + QString::number(element.getQuantity()));
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::delete_item);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filter_categ);
}

void GUI::delete_item() {
    int selectedIndex = this->get_selected_index();
    if (selectedIndex == -1) {
        QMessageBox::critical(this, "Error", "Select the item to be deleted");
        return;
    }
    Item item = this->service.getData()[selectedIndex];
    this->service.delete_item_service(item.getCategory(), item.getName());
    this->populate_list();
}

void GUI::filter_categ() {
    string category = this->categoryEdit->text().toStdString();
    if (category.empty())
        this->populate_list();
    else {
        this->shoppingListWidget->clear();
        vector<Item> data = this->service.filter_by_category(category);
        for (auto& element : data)
            this->shoppingListWidget->addItem(QString::fromStdString(element.getCategory() + " | " + element.getName() + " | ") + QString::number(element.getQuantity()));
    }
}

int GUI::get_selected_index() {
    QModelIndexList selectedIndexes = this->shoppingListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty())
        return -1;
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}
