//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_STUDENTWINDOW_H
#define BACHELOR_THESES_STUDENTWINDOW_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Service/Service.h"
#include "../Teacher/Teacher.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>


class StudentWindow : public QWidget, public Observer {
private:
    Service& service;
    Teacher& t;

    QListWidget* studentsListWidget;
    QLineEdit* emailLineEdit, *titleLineEdit;
    QPushButton* saveButton, *cancelButton;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    vector<Student> students;
    string email;
    string title;

public:
    StudentWindow(Service& service, Teacher& t);

    void initGUI();

    void update() override;

    void connectSignals();

    void populateList(vector<Student> elems);

    void saveChanges();

    void cancelChanges();

    int getSelectedIndex();

    ~StudentWindow() override;
};


#endif //BACHELOR_THESES_STUDENTWINDOW_H
