//
// Created by paula on 6/21/2021.
//

#include "Teacher.h"

Teacher::Teacher(string name): name{name} {

}

string Teacher::getName() {
    return this->name;
}

istream &operator>>(istream &input, Teacher &t) {
    input >> t.name;
    return input;
}
