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
//    QFont font("Helvetica", 10, QFont::Bold);
    this->setWindowTitle("Tasks");

    this->taskListWidget = new QListWidget{};
//    this->taskListWidget->setFont(font);
    this->durationButton = new QPushButton{"Show duration"};
//    this->durationButton->setFont(font);
    this->priorityButton = new QPushButton{"Bold tasks with priority 1"};
    this->priorityEdit = new QLineEdit{};
//    this->priorityEdit->setFont(font);

    QVBoxLayout* mainLayout = new QVBoxLayout{};
    mainLayout->addWidget(this->taskListWidget);
    mainLayout->addWidget(this->priorityButton);

    QFormLayout* modelLayout = new QFormLayout{};
    modelLayout->addRow("Priority", this->priorityEdit);
    modelLayout->addWidget(this->durationButton);

    mainLayout->addLayout(modelLayout);

    setLayout(mainLayout);
}

void GUI::populate_list() {
    this->taskListWidget->clear();
    vector<Task> data = this->service.sort_by_priority();

    for (auto &element : data) {
        this->taskListWidget->addItem(QString::fromStdString(element.getDescription() + " | ") + QString::number(element.getPriority()));
    }
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->durationButton, &QPushButton::clicked, this, &GUI::compute_duration);
    QObject::connect(this->priorityButton, &QPushButton::clicked, this, &GUI::bold_priority1);
}

void GUI::compute_duration() {
    string priority = this->priorityEdit->text().toStdString();
    if (priority.empty()) {
        QMessageBox::critical(this, "Error", "Introduce a priority");
        return;
    }
    int priorityInt = stoi(priority);
    int duration = this->service.compute_total_duration(priorityInt);
    QMessageBox msgBox;
    msgBox.setText("The total duration of the given priority is " + QString::number(duration));
    msgBox.exec();
}

void GUI::bold_priority1() {
    this->taskListWidget->clear();
    for (auto &element : this->service.sort_by_priority()) {
        if (element.getPriority() == 1) {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(element.getDescription() + " | ") + QString::number(element.getPriority()));
            QFont *font = new QFont{};
            font->setBold(true);
            item->setFont(*font);
            this->taskListWidget->addItem(item);
        }
        else {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(element.getDescription() + " | ") + QString::number(element.getPriority()));
            this->taskListWidget->addItem(item);
        }
    }
}
