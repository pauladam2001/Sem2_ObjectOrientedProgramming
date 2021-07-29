//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_TEACHERWINDOW_H
#define BACHELOR_THESES_TEACHERWINDOW_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Service/Service.h"
#include "../Teacher/Teacher.h"
#include "../StudentWindow/StudentWindow.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>


class TeacherWindow : public QWidget, public Observer {
private:
    Service& service;
    Teacher& t;

    QListWidget* studentsListWidget, *allStudentsListWidget;
    QPushButton* openWindowButton, *addCoordinatorButton;
    QLineEdit* searchLineEdit;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    vector<Student> allStudents;

public:
    TeacherWindow(Service& service, Teacher& t);

    void update() override;

    void notifyMode();

    int getSelectedIndex();

    void connectSignals();

    void initGUI();

    void populateList(vector<Student> elems);

    void populateListAllStudents(vector<Student> elems);

    void makeCoordinator();

    void search();

    void check();

    void openWindow();

    ~TeacherWindow() override;
};


#endif //BACHELOR_THESES_TEACHERWINDOW_H
