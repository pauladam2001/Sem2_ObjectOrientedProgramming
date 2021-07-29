//
// Created by paula on 6/21/2021.
//

#include "StudentWindow.h"

StudentWindow::StudentWindow(Service &service, Teacher &t): service{service}, t{t} {
    this->service.addObserver(this);
    this->initGUI();
    this->populateList(this->service.filteredYear(this->t.getName()));
    this->connectSignals();
}

void StudentWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->studentsListWidget = new QListWidget{};
    this->studentsListWidget->setFont(buttonsFont);

    this->titleLineEdit = new QLineEdit{};
    this->titleLineEdit->setFont(buttonsFont);

    this->emailLineEdit = new QLineEdit{};
    this->emailLineEdit->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout{};
    this->buttonsLayout = new QGridLayout{};

    this->saveButton = new QPushButton("Save");
    this->saveButton->setFont(buttonsFont);

    this->cancelButton = new QPushButton("Cancel");
    this->cancelButton->setFont(buttonsFont);

    this->mainLayout->addWidget(this->studentsListWidget);

    QLabel* titleLabel = new QLabel("Title");
    titleLabel->setFont(buttonsFont);

    QLabel* emailLabel = new QLabel("Email");
    emailLabel->setFont(buttonsFont);

    this->buttonsLayout->addWidget(titleLabel, 0, 0);
    this->buttonsLayout->addWidget(emailLabel, 0, 1);
    this->buttonsLayout->addWidget(this->titleLineEdit, 1, 0);
    this->buttonsLayout->addWidget(this->emailLineEdit, 1, 1);
    this->buttonsLayout->addWidget(this->saveButton, 2, 0);
    this->buttonsLayout->addWidget(this->cancelButton, 2, 1);

    this->mainLayout->addLayout(buttonsLayout);

    this->setLayout(mainLayout);
    this->resize(700,500);
}

void StudentWindow::connectSignals() {
    QObject::connect(this->studentsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getSelectedIndex();
        if(index < 0)
            return;

        Student s = this->students[index];
        this->emailLineEdit->setText(QString::fromStdString(s.getEmail()));
        this->titleLineEdit->setText(QString::fromStdString(s.getTitle()));
        this->email=s.getEmail();
        this->title = s.getTitle();
    });
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &StudentWindow::saveChanges);
    QObject::connect(this->cancelButton, &QPushButton::clicked, this, &StudentWindow::cancelChanges);
}

void StudentWindow::populateList(vector<Student> elems) {
    if (elems.empty()) {
        this->studentsListWidget->clear();
        this->students.clear();
    }
    else {
        this->studentsListWidget->clear();
        this->students.clear();
        this->students = elems;
        for (auto& s : elems)
            this->studentsListWidget->addItem(QString::fromStdString(
                    s.getId() + " | " + s.getName() + " | " + s.getEmail() + " | " + to_string(s.getYear()) + " | " +
                    s.getTitle() + " | " + s.getCoordinator()));
    }
}

void StudentWindow::update() {
    this->populateList(this->service.filteredYear(this->t.getName()));
}

void StudentWindow::saveChanges() {
    string emaill = this->emailLineEdit->text().toStdString();
    string titlee = this->titleLineEdit->text().toStdString();
    int index = this->getSelectedIndex();
    Student &s = this->students[index];
    if (emaill.empty() || titlee.empty()) {
        QMessageBox::critical(this, "Error", "Invalid title and email!");
        return;
    }
    else
        this->service.changeTitleAndEmail(s, titlee, emaill);
}

void StudentWindow::cancelChanges() {
    this->emailLineEdit->setText(QString::fromStdString(this->email));
    this->titleLineEdit->setText(QString::fromStdString(this->title));
}

int StudentWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->studentsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty()){
        this->emailLineEdit->clear();
        this->titleLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

StudentWindow::~StudentWindow() = default;
