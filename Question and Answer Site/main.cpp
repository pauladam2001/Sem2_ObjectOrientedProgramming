#include <iostream>
#include <QApplication>
#include "UserRepo.h"
#include "AnswerRepo.h"
#include "QuestionRepo.h"
#include "Service.h"
#include "UserWindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    UserRepo users;
    AnswerRepo answers;
    QuestionRepo questions;
    Service service(users, answers, questions);

    vector<UserWindow*> windows;
    for(auto & u: users.getUsers()){
        windows.push_back(new UserWindow(service, u));
    }

    return a.exec();
}
