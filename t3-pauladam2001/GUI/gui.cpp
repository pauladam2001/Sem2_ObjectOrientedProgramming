//
// Created by paula on 5/24/2021.
//

#include "gui.h"
#include <QVBoxLayout>
#include <QFormLayout>


GUI::GUI(Service &service):service{service} {
    this->init_GUI();
    this->populate_list();
    this->connectSignalsAndSlots();
}

GUI::~GUI() {

}

void GUI::init_GUI() {
    QFont font("Helvetica", 10, QFont::Bold);
    this->setWindowTitle("Weather");

    this->weatherListWidget = new  QListWidget{};
    this->weatherListWidget->setFont(font);
    this->slider = new QSlider{Qt::Horizontal};
    this->slider->setRange(1, 100);
    this->slider->setFont(font);

    this->checkBox1 = new QCheckBox{};
    this->checkBox1->setFont(font);
    this->checkBox2 = new QCheckBox{};
    this->checkBox2->setFont(font);
    this->checkBox3 = new QCheckBox{};
    this->checkBox3->setFont(font);
    this->checkBox4 = new QCheckBox{};
    this->checkBox4->setFont(font);
    this->checkBox5 = new QCheckBox{};
    this->checkBox5->setFont(font);

    this->button = new QPushButton{"Return to the unfiltered list"};
    this->button->setFont(font);

    QVBoxLayout* mainLayout = new QVBoxLayout{};
    mainLayout->addWidget(this->weatherListWidget);
    mainLayout->addWidget(this->slider);

    QFormLayout* secLayout = new QFormLayout{};
    secLayout->addRow("overcast", this->checkBox1);
    secLayout->addRow("foggy", this->checkBox2);
    secLayout->addRow("sunny", this->checkBox3);
    secLayout->addRow("rain", this->checkBox4);
    secLayout->addRow("thunderstorm", this->checkBox5);

//    QVBoxLayout* secLayout = new QVBoxLayout{};
//    this->init_checkboxes();
//    for(auto &elem: this->checkboxes)
//        secLayout->addWidget(elem);

    mainLayout->addLayout(secLayout);
    mainLayout->addWidget(this->button);

    setLayout(mainLayout);
}

void GUI::populate_list() {
    this->weatherListWidget->clear();
    vector<TimeInterval> data = this->service.getData();

    for (auto &element: data)
        this->weatherListWidget->addItem(QString::number(element.getStartHour()) + " - " + QString::number(element.getEndHour()) + " - " + QString::number(element.getProbability()) + " - " + QString::fromStdString(element.getDescription()));
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->slider, &QSlider::valueChanged, this, &GUI::filter_list);
    QObject::connect(this->checkBox1, &QCheckBox::clicked, this, &GUI::filter_checkbox);
    QObject::connect(this->checkBox2, &QCheckBox::clicked, this, &GUI::filter_checkbox);
    QObject::connect(this->checkBox3, &QCheckBox::clicked, this, &GUI::filter_checkbox);
    QObject::connect(this->checkBox4, &QCheckBox::clicked, this, &GUI::filter_checkbox);
    QObject::connect(this->checkBox5, &QCheckBox::clicked, this, &GUI::filter_checkbox);
//    for(auto &checkbox:this->checkboxes)
//        QObject::connect(checkbox, &QCheckBox::clicked, this, &GUI::filter_checkbox);
    QObject::connect(this->button, &QPushButton::clicked, this, &GUI::return_to_unfiltered);
    QObject::connect(this->slider, &QSlider::valueChanged, this, &GUI::filter_through_both);
    QObject::connect(this->checkBox1, &QCheckBox::clicked, this, &GUI::filter_through_both);
    QObject::connect(this->checkBox2, &QCheckBox::clicked, this, &GUI::filter_through_both);
    QObject::connect(this->checkBox3, &QCheckBox::clicked, this, &GUI::filter_through_both);
    QObject::connect(this->checkBox4, &QCheckBox::clicked, this, &GUI::filter_through_both);
    QObject::connect(this->checkBox5, &QCheckBox::clicked, this, &GUI::filter_through_both);
//    for(auto &checkbox:this->checkboxes)
//        QObject::connect(checkbox, &QCheckBox::clicked, this, &GUI::filter_checkbox);
}

void GUI::filter_list() {
    int probability = this->slider->value();
    this->weatherListWidget->clear();
    vector<TimeInterval> data = this->service.filter(probability);

    for (auto &element:data)
        this->weatherListWidget->addItem(QString::number(element.getStartHour()) + " - " + QString::number(element.getEndHour()) + " - " + QString::number(element.getProbability()) + " - " + QString::fromStdString(element.getDescription()));
}

void GUI::filter_checkbox() {
    bool sem = false;
    string string1, string2, string3, string4, string5;
    if (this->checkBox1->isChecked()) {
        string1 = "overcast";
        sem = true;
    }
    if (this->checkBox2->isChecked()) {
        string2 = "foggy";
        sem = true;
    }
    if (this->checkBox3->isChecked()) {
        string3 = "sunny";
        sem = true;
    }
    if (this->checkBox4->isChecked()) {
        string4 = "rain";
        sem = true;
    }
    if (this->checkBox5->isChecked()) {
        string5 = "thunderstorm";
        sem = true;
    }

//    vector<string> descriptions;
//    for (auto& checkbox: this->checkboxes) {
//        if (checkbox->isChecked()) {
//            string text = checkbox->text().toStdString();
//            descriptions.push_back(text);
//        }
//    }

    this->weatherListWidget->clear();
    vector<TimeInterval> data;
    if (sem)
        data = this->service.filter_checkbox(string1, string2, string3, string4, string5);
    else
        data = this->service.getData();

    for (auto &element:data)
        this->weatherListWidget->addItem(QString::number(element.getStartHour()) + " - " + QString::number(element.getEndHour()) + " - " + QString::number(element.getProbability()) + " - " + QString::fromStdString(element.getDescription()));
}

void GUI::return_to_unfiltered() {
    this->slider->setValue(100);
    if (this->checkBox1->isChecked())
        this->checkBox1->setChecked(false);
    if (this->checkBox2->isChecked())
        this->checkBox2->setChecked(false);
    if (this->checkBox3->isChecked())
        this->checkBox3->setChecked(false);
    if (this->checkBox4->isChecked())
        this->checkBox4->setChecked(false);
    if (this->checkBox5->isChecked())
        this->checkBox5->setChecked(false);
    this->populate_list();
}

void GUI::filter_through_both() {
    bool sem = false;
    int probability = this->slider->value();
    string string1, string2, string3, string4, string5;
    if (this->checkBox1->isChecked()) {
        string1 = "overcast";
        sem = true;
    }
    if (this->checkBox2->isChecked()) {
        string2 = "foggy";
        sem = true;
    }
    if (this->checkBox3->isChecked()) {
        string3 = "sunny";
        sem = true;
    }
    if (this->checkBox4->isChecked()) {
        string4 = "rain";
        sem = true;
    }
    if (this->checkBox5->isChecked()) {
        string5 = "thunderstorm";
        sem = true;
    }

    this->weatherListWidget->clear();
    vector<TimeInterval> data;
    if (sem)
        data = this->service.filter_both(probability, string1, string2, string3, string4, string5);
    else
        data = this->service.filter(probability);

    for (auto &element:data)
        this->weatherListWidget->addItem(QString::number(element.getStartHour()) + " - " + QString::number(element.getEndHour()) + " - " + QString::number(element.getProbability()) + " - " + QString::fromStdString(element.getDescription()));
}

void GUI::init_checkboxes() {
    vector<TimeInterval> data = this->service.getData();
    for (auto &element:data) {
        bool found = false;
        for (auto &desc: this->descriptions)
            if (desc == element.getDescription())
                found = true;
        if (found == false)
            this->descriptions.push_back(element.getDescription());
    }
    for (auto &element: this->descriptions){
        QCheckBox* newCheckBox = new QCheckBox;
        newCheckBox->setText(QString::fromStdString(element));
        this->checkboxes.push_back(newCheckBox);
    }
}
