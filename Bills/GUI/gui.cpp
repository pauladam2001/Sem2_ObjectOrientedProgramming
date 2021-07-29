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
    this->setWindowTitle("Tasks");

    this->billsListWidget = new QListWidget{};
    this->billsListWidget->setFont(font);
    this->sortButton = new QPushButton{"Sort the list"};
    this->sortButton->setFont(font);
    this->unpaidButton = new QPushButton{"Calculate total"};
    this->unpaidButton->setFont(font);
    this->unpaidLineEdit = new QLineEdit{};
    this->unpaidLineEdit->setFont(font);
    this->resultLineEdit = new QLineEdit{};
    this->resultLineEdit->setFont(font);

    QVBoxLayout* mainLayout = new QVBoxLayout{};
    mainLayout->addWidget(this->billsListWidget);
    mainLayout->addWidget(this->sortButton);

    QFormLayout* unpaidLayout = new QFormLayout{};
    unpaidLayout->addRow("Company name", this->unpaidLineEdit);
    unpaidLayout->addWidget(this->unpaidButton);
    unpaidLayout->addRow("Amount to pay", this->resultLineEdit);

    mainLayout->addLayout(unpaidLayout);

    setLayout(mainLayout);
}

void GUI::populate_list() {
    this->billsListWidget->clear();
    vector<Bill> data = this->service.getData();

    for (auto &element : data) {
        this->billsListWidget->addItem(QString::fromStdString(element.getCompany() + " | " + to_string(element.getSum())));
    }
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->sortButton, &QPushButton::clicked, this, &GUI::sort_list);
    QObject::connect(this->unpaidButton, &QPushButton::clicked, this, &GUI::calculate_unpaid);
}

void GUI::sort_list() {
    this->billsListWidget->clear();
    vector<Bill> data = this->service.sort_by_company();

    for (auto &element : data)
        this->billsListWidget->addItem(QString::fromStdString(element.getCompany() + " | " + to_string(element.getSum())));
}

void GUI::calculate_unpaid() {
//    this->billsListWidget->clear();
//    for (auto &element : this->service.sort_by_company()) {
//        if (element.getPriority() == 1) {
//            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(element.getDescription() + " | ") + QString::number(element.getPriority()));
//            QFont *font = new QFont{};
//            font->setBold(true);
//            item->setFont(*font);
//            this->billsListWidget->addItem(item);
//        }
//        else {
//            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(element.getDescription() + " | ") + QString::number(element.getPriority()));
//            this->billsListWidget->addItem(item);
//        }
//    }

    string company = this->unpaidLineEdit->text().toStdString();
    if (company.empty()) {
        QMessageBox::critical(this, "Error", "Provide a company name!");
        return;
    }
    double total = this->service.unpaid_company_bills(company);
    this->resultLineEdit->setText(QString::fromStdString(to_string(total)));
}
