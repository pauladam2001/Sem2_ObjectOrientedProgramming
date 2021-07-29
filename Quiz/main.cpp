#include <iostream>
#include <QApplication>
#include "Repository/RepoQuestions.h"
#include "Repository/RepoParticipants.h"
#include "PresenterWindow/PresenterWindow.h"
#include "ParticipantWindow/ParticipantWindow.h"


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    RepoQuestion repoQuestion;
    RepoParticipants repoParticipants;

    vector<ParticipantWindow*> windows;
    for (auto &p : repoParticipants.getParticipants())
        windows.push_back(new ParticipantWindow(repoQuestion, repoParticipants, p));

    PresenterWindow presenterWindow(repoQuestion);

    return a.exec();
}
