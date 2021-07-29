//
// Created by paula on 6/18/2021.
//

#ifndef ACTION_UML_DIAGRAM_WRITTEN_MENUITEM_H
#define ACTION_UML_DIAGRAM_WRITTEN_MENUITEM_H

#include <string>
#include <vector>
#include "../action/Action.h"

using namespace std;


class MenuItem {
private:
    string text;
    Action* action;

public:
    MenuItem() = default;

    MenuItem(string text, Action* action);

    virtual void print();

    void clicked();
};


class Menu : public MenuItem {
private:
    vector<MenuItem> data;

public:
    Menu() = default;

    void add(MenuItem mi);

    void print() override;
};


class MenuBar {
private:
    vector<MenuItem> data;

public:
    MenuBar() = default;

    void add(Menu menu);

    void print();
};


#endif //ACTION_UML_DIAGRAM_WRITTEN_MENUITEM_H
