//
// Created by paula on 6/22/2021.
//

#include "Ethnologist.h"

Ethnologist::Ethnologist(string name, string area): name{name}, area{area} {

}

string Ethnologist::getName() {
    return this->name;
}

string Ethnologist::getArea() {
    return this->area;
}

vector<string> Ethnologist::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream &operator>>(istream &input, Ethnologist &e) {
    string line;
    getline(input, line);
    vector<string> tokens = Ethnologist::tokenize(line, ';');
    if (tokens.size() != 2)
        return input;
    e.name = tokens[0];
    e.area = tokens[1];
    return input;
}
