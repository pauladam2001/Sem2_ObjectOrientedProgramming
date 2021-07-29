//
// Created by paula on 6/18/2021.
//

#include "MenuItem.h"

MenuItem::MenuItem(string text, Action *action): text{text}, action{action} {

}

void MenuItem::print() {
    cout << this->text << "\n";
}

void MenuItem::clicked() {
    cout << this->text << "\n";
    action->execute();
}



void Menu::add(MenuItem mi) {
    this->data.push_back(mi);
}

void Menu::print() {
    for (auto& elem : this->data) {
        elem.print();
        cout << ", ";
    }
}



void MenuBar::add(Menu menu) {
    this->data.push_back(menu);
}

void MenuBar::print() {
    for (auto& elem : this->data) {
        elem.print();
        cout << ", ";
    }
}
