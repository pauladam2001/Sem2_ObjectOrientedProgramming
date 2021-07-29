//
// Created by paula on 6/21/2021.
//

#include "TeacherWindow.h"

TeacherWindow::TeacherWindow(Service &service, Teacher &t): service{service}, t{t} {
    this->service.addObserver(this);
    this->initGUI();
    this->populateList(this->service.filteredYear(this->t.getName()));
    this->connectSignals();
    this->show();
}

void TeacherWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->studentsListWidget = new QListWidget{};
    this->studentsListWidget->setFont(buttonsFont);

    this->allStudentsListWidget = new QListWidget{};
    this->allStudentsListWidget->setFont(buttonsFont);

    this->searchLineEdit = new QLineEdit{};
    this->searchLineEdit->setFont(buttonsFont);

    this->openWindowButton = new QPushButton{"Open window"};
    this->openWindowButton->setFont(buttonsFont);

    this->addCoordinatorButton = new QPushButton{"Add coordinator"};
    this->addCoordinatorButton->setFont(buttonsFont);
    this->addCoordinatorButton->setEnabled(false);

    this->mainLayout = new QVBoxLayout{};
    this->buttonsLayout = new QGridLayout{};

    this->buttonsLayout->addWidget(this->studentsListWidget, 0, 0);
    this->buttonsLayout->addWidget(this->allStudentsListWidget, 0, 1);
    this->buttonsLayout->addWidget(this->openWindowButton, 1, 0);
    this->buttonsLayout->addWidget(this->searchLineEdit, 1, 1);
    this->buttonsLayout->addWidget(this->addCoordinatorButton, 2, 1);

    this->mainLayout->addLayout(buttonsLayout);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->t.getName()));
    this->resize(700,500);
}

void TeacherWindow::connectSignals() {
    QObject::connect(this->addCoordinatorButton, &QPushButton::clicked, this, &TeacherWindow::makeCoordinator);
    QObject::connect(this->openWindowButton, &QPushButton::clicked, this, &TeacherWindow::openWindow);
    QObject::connect(this->searchLineEdit, &QLineEdit::textChanged, this, &TeacherWindow::search);
    QObject::connect(this->allStudentsListWidget, &QListWidget::clicked, this, &TeacherWindow::check);
}

void TeacherWindow::update() {
    this->populateList(this->service.filteredYear(this->t.getName()));
    this->search();
}

void TeacherWindow::notifyMode() {

}

int TeacherWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->allStudentsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

void TeacherWindow::populateList(vector<Student> elems) {
    if (elems.empty())
        return;

    this->studentsListWidget->clear();
    for (auto& s : elems)
        this->studentsListWidget->addItem(QString::fromStdString(s.getId() + " | " + s.getName() + " | " + s.getEmail() + " | " + to_string(s.getYear()) + " | " +
                                                                 s.getTitle() + " | " + s.getCoordinator()));
}

void TeacherWindow::populateListAllStudents(vector<Student> elems) {
    this->allStudentsListWidget->clear();
    for (auto& s : elems)
        this->allStudentsListWidget->addItem(QString::fromStdString(s.getId() + " | " + s.getName() + " | " + s.getEmail() + " | " + to_string(s.getYear()) + " | " +
                                                                    s.getTitle() + " | " + s.getCoordinator()));
}

void TeacherWindow::makeCoordinator() {
    int index = this->getSelectedIndex();
    Student& student = this->allStudents[index];
    string name = this->t.getName();
    this->service.makeCoordinator(student, name);
    this->addCoordinatorButton->setEnabled(false);
}

void TeacherWindow::search() {
    string name = this->searchLineEdit->text().toStdString();
    if (name.empty()) {
        this->allStudentsListWidget->clear();
        this->allStudents.clear();
    }
    else {
        vector<Student> students = this->service.filterStudentsName(name);
        this->allStudents = students;
        this->populateListAllStudents(students);
    }
}

void TeacherWindow::check() {
    int index = this->getSelectedIndex();
    Student s = this->allStudents[index];
    if (s.getCoordinator().empty())
        this->addCoordinatorButton->setEnabled(true);
    else
        this->addCoordinatorButton->setEnabled(false);
}

void TeacherWindow::openWindow() {
    StudentWindow* w = new StudentWindow(this->service, this->t);
    w->show();
}

TeacherWindow::~TeacherWindow() {
    this->service.removeObserver(this);
}
