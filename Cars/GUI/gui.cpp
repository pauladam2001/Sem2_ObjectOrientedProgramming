//
// Created by paula on 5/20/2021.
//

#include "gui.h"
#include <QFont>
#include <QVBoxLayout>
#include <QFormLayout>
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
    this->setWindowTitle("Cars");

    this->carListWidget = new QListWidget{};
    this->carListWidget->setFont(font);
    this->colorButton = new QPushButton{"Show cars colored"};
    this->colorButton->setFont(font);
    this->modelButton = new QPushButton{"Show the number of cars"};
    this->modelButton->setFont(font);
    this->modelEdit = new QLineEdit{};
    this->modelEdit->setFont(font);

    QVBoxLayout* mainLayout = new QVBoxLayout{};
    mainLayout->addWidget(carListWidget);
    mainLayout->addWidget(colorButton);

    QFormLayout* modelLayout = new QFormLayout{};
    modelLayout->addRow("Manufacturer", this->modelEdit);
    modelLayout->addWidget(this->modelButton);

    mainLayout->addLayout(modelLayout);

    setLayout(mainLayout);
}

void GUI::populate_list() {
    this->carListWidget->clear();
    vector<Car> data = this->service.sort_by_name();

    for (auto &element : data) {
        this->carListWidget->addItem(QString::fromStdString(element.getName() + "|" + element.getModel()));
    }
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->colorButton, &QPushButton::clicked, this, &GUI::change_color);
    QObject::connect(this->modelButton, &QPushButton::clicked, this, &GUI::show_nr_of_cars);
}

void GUI::change_color() {
    this->carListWidget->clear();
    for (auto &element: this->service.sort_by_name()) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(element.getName() + "|" + element.getModel()));
        string color = element.getColor();
        item->setTextColor(QString::fromStdString(color));
        this->carListWidget->addItem(item);
    }
}

void GUI::show_nr_of_cars() {
    string name = this->modelEdit->text().toStdString();
    if (name.empty()) {
        QMessageBox::critical(this, "Error", "Provide a manufacturer!");
        return;
    }
    int total = this->service.nr_of_cars(name);
    QMessageBox msgBox;
    msgBox.setText("The number of cars that have the given manufacturer is " + QString::number(total));
    msgBox.exec();
}
