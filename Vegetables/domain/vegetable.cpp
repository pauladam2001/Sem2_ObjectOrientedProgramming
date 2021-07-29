//
// Created by paula on 5/20/2021.
//

#include "vegetable.h"
#include <sstream>
#include <iostream>

Vegetable::Vegetable() {

}

Vegetable::Vegetable(string family, string name, string parts): family{family}, name{name}, parts{parts} {

}

string Vegetable::getFamily() {
    return this->family;
}

string Vegetable::getName() {
    return this->name;
}

string Vegetable::getParts() {
    return this->parts;
}

Vegetable::~Vegetable() {

}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, Vegetable &v) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, '|');
    if (tokens.size() != 3)
        return is;
    v.family = tokens[0];
    v.name = tokens[1];
    v.parts = tokens[2];
    return is;
}
