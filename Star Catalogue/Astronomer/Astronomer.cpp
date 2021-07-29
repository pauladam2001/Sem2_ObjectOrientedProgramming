//
// Created by paula on 6/20/2021.
//

#include "Astronomer.h"

Astronomer::Astronomer() = default;

Astronomer::Astronomer(string name, string constellation): name{name}, constellation{constellation} {

}

string Astronomer::getName() {
    return this->name;
}

string Astronomer::getConstellation() {
    return this->constellation;
}

istream &operator>>(istream &input, Astronomer &a) {
    input>>a.name>>a.constellation;
    return input;
}

Astronomer::~Astronomer() = default;
