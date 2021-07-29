//
// Created by Alexandra on 6/20/2021.
//

#include "User.h"

istream &operator>>(istream &input, User &u) {
    input>>u.name;
    return input;
}

User::User() {

}

User::User(string name): name{name} {

}

User::~User() {

}

string User::getName() {
    return this->name;
}
