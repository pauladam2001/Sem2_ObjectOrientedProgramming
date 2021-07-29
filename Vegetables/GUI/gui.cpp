//
// Created by paula on 5/20/2021.
//

#include "gui.h"
#include <QFont>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>

GUI::GUI(Service &service):service{service} {
    this->init_GUI();
    this->populate_list();
    this->connectSignalsAndSlots();
}

GUI::~GUI() {

}

void GUI::init_GUI() {
    QFont font("Helvetica", 10, QFont::Bold);
    this->setWindowTitle("Tasks");

    this->familiesListWidget = new QListWidget{};
    this->familiesListWidget->setFont(font);
    this->vegetablesListWidget = new QListWidget{};
    this->vegetablesListWidget->setFont(font);
    this->searchButton = new QPushButton{"Search"};
    this->searchButton->setFont(font);
    this->nameLineEdit = new QLineEdit{};
    this->nameLineEdit->setFont(font);
    this->partsConsumedLineEdit = new QLineEdit{};
    this->partsConsumedLineEdit->setFont(font);

    QFormLayout* secLayout = new QFormLayout{};
    secLayout->addRow("Vegetable name", this->nameLineEdit);
    secLayout->addWidget(this->searchButton);
    secLayout->addRow("Consumable", this->partsConsumedLineEdit);

    QGridLayout* mainLayout = new QGridLayout{this};
    mainLayout->addWidget(this->familiesListWidget, 0, 0);
    mainLayout->addWidget(this->vegetablesListWidget, 0, 1);
    mainLayout->addLayout(secLayout, 1, 0);

    setLayout(mainLayout);
}

void GUI::populate_list() {
    this->familiesListWidget->clear();
    vector<string> data = this->service.get_unique_families();

    for (auto &element : data)
        this->familiesListWidget->addItem(QString::fromStdString(element));
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->searchButton, &QPushButton::clicked, this, &GUI::highlight_vegetable_and_get_parts);
    QObject::connect(this->familiesListWidget, &QListWidget::itemSelectionChanged, this, &GUI::add_to_vegetablesList);
}

void GUI::add_to_vegetablesList() {
    int selectedIndex = this->get_selected_index();

    if (selectedIndex == -1)
        return;

    this->vegetablesListWidget->clear();

    string family = this->service.get_unique_families()[selectedIndex];

    vector<Vegetable> data = this->service.get_family_vegetables(family);

    for (auto &element : data)
        this->vegetablesListWidget->addItem(QString::fromStdString(element.getName() + ": " + element.getParts()));
}

int GUI::get_selected_index() {
    QModelIndexList selectedIndexes = this->familiesListWidget->selectionModel()->selectedIndexes();

    if (selectedIndexes.empty()) {
        return -1;
    }

    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void GUI::highlight_vegetable_and_get_parts() {
    string name = this->nameLineEdit->text().toStdString();
    if (name.empty()) {
        QMessageBox::critical(this, "Error", "Provide a name!");
        return;
    }

    string parts;
    string family;
    vector<Vegetable> vegetables = this->service.getData();
    for (auto& element: vegetables)
        if (element.getName() == name) {
            parts = element.getParts();
            family = element.getFamily();
            break;
        }
    this->partsConsumedLineEdit->setText(QString::fromStdString(parts));

    vector<string> families = this->service.get_unique_families();
    this->familiesListWidget->clear();
    for (auto & element : families) {
        if (element == family) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(element));
            item->setBackground(Qt::red);
            this->familiesListWidget->addItem(item);
        }
        else
            this->familiesListWidget->addItem(QString::fromStdString(element));
    }
}
