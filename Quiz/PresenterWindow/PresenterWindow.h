//
// Created by paula on 6/21/2021.
//

#ifndef QUIZ_PRESENTERWINDOW_H
#define QUIZ_PRESENTERWINDOW_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Repository/RepoQuestions.h"
#include "../Participant/Participant.h"
#include "../TableModel/TableModelPresenter.h"
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>


class PresenterWindow : public QWidget, public Observer {
private:
    RepoQuestion& repo;
    QLineEdit* idLineEdit, *textLineEdit, *correctAnswerLineEdit;
    QPushButton* addButton;
    QTableView* questionsTableView;
    TableModelPresenter* tableModel;
    QLabel* idLabel, *textLabel, *correctAnswerLabel;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;

public:
    PresenterWindow(RepoQuestion& repo, QWidget* parent = Q_NULLPTR);

    void update() override;

    void notifyModel();

    void initGUI();

    void connectSignals();

    void addQuestion();

    ~PresenterWindow() override;
};


#endif //QUIZ_PRESENTERWINDOW_H
