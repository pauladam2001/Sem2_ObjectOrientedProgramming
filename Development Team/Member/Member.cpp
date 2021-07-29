//
// Created by paula on 6/20/2021.
//

#include "Member.h"


Member::Member(string name, string type): name{name}, type{type} {

}

string Member::getName() {
    return this->name;
}

string Member::getType() {
    return this->type;
}

std::istream &operator>>(istream &input, Member &m) {
    input >> m.name >> m.type;
    return input;
}
