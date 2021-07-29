//
// Created by Alexandra on 6/21/2021.
//

#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include "TableModel.h"
#include "Observer.h"
#include "Service.h"
#include "User.h"
#include <QSpinBox>

class UserWindow: public QWidget, public Observer{

private:
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    Service& service;
    User& u;
    TableModel* tableModel;
    QTableView* questionsTableView;
    QPushButton* addQuestionButton, *addAnswerButton;
    QLineEdit* questionTextLineEdit, *answerLineEdit;
    QListWidget* answersListWidget;
    QSpinBox* voteSpinBox;
    QMetaObject::Connection myConnect;
    int currentIndexTableView = -1;


public:
    UserWindow(Service& service, User& u, QWidget*parent = Q_NULLPTR);
    ~UserWindow();
    void update() override;
    void notifyModel();
    void initGUI();
    void initAnswersGUI();
    void connectSignals();
    void addQuestion();
    void addAnswer();
    void populateList();
    void changeQSpinBox();
    int getSelectedIndexList();
    void connectSignals2();
    void voteAnswer();

};


