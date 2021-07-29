//
// Created by paula on 6/18/2021.
//

#ifndef ACTION_UML_DIAGRAM_WRITTEN_ACTION_H
#define ACTION_UML_DIAGRAM_WRITTEN_ACTION_H

#include <iostream>

using namespace std;


class Action {
public:
    virtual void execute() = 0;
};


class CreateAction : public Action {
public:
    CreateAction() = default;

    void execute() override {
        cout << "Create file\n";
    }
};


class ExitAction : public Action {
public:
    ExitAction() = default;

    void execute() override {
        cout << "Exit application\n";
    }
};


#endif //ACTION_UML_DIAGRAM_WRITTEN_ACTION_H
