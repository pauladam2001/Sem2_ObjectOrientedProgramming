//
// Created by paula on 6/22/2021.
//

#include "Contacts.h"

Person::Person(string name): Contact(){
    this->name = name;
}

void Person::sendMessage(Message *m) {
    cout << "Sending message " << m->getMessage() << " to " << this->name << "\n";
}



Group::Group(string name): Contact() {
    this->name = name;
}

void Group::addContact(Contact *c) {
    this->data.push_back(c);
}

void Group::sendMessage(Message *m) {
    for (auto& c : this->data)
        c->sendMessage(m);
}
