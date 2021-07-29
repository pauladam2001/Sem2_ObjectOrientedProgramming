//
// Created by paula on 6/22/2021.
//

#ifndef PROBLEM3_CONTACTS_H
#define PROBLEM3_CONTACTS_H

#include "Messages.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Contact {
protected:
    string name;

public:
    virtual void addContact(Contact* c) = 0;

    virtual void sendMessage(Message* m) = 0;

    virtual ~Contact() = default;
};


class Person : public Contact {
public:
    Person(string name);

    void sendMessage(Message* m) override;

    void addContact(Contact* c) override {
        ;
    }
};


class Group : public Contact {
private:
    vector<Contact*> data;

public:
    Group(string name);

    void addContact(Contact* c) override;

    void sendMessage(Message* m) override;
};


#endif //PROBLEM3_CONTACTS_H
