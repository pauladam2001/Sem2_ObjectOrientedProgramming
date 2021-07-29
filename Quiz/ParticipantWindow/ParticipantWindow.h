//
// Created by paula on 6/21/2021.
//

#ifndef QUIZ_PARTICIPANTWINDOW_H
#define QUIZ_PARTICIPANTWINDOW_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Repository/RepoQuestions.h"
#include "../Repository/RepoParticipants.h"
#include "../Participant/Participant.h"
#include "../TableModel/TableModel.h"
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include <QSortFilterProxyModel>


class ParticipantWindow : public QWidget, public Observer {
private:
    RepoParticipants& repoParticipants;
    RepoQuestion& repo;
    Participant& p;

    TableModel* tableModel;
    QTableView* questionsTableView;
    QLineEdit* answerLineEdit;
    QPushButton* answerButton;
    QLabel* answerLabel;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QLabel* scoreLabel;

public:
    ParticipantWindow(RepoQuestion& repo, RepoParticipants& repoParticipants, Participant& p, QWidget* parent = Q_NULLPTR);

    void initGUI();

    void connectSignals();

    void notifyModel();

    void update() override;

    void answerQuestion();

    void checkIfAnswered(const QModelIndex& index);

    ~ParticipantWindow() override;
};


#endif //QUIZ_PARTICIPANTWINDOW_H
