//
// Created by paula on 5/20/2021.
//

#include "car.h"
#include <sstream>
#include <iostream>

Car::Car() {

}

Car::Car(string name, string model, int year, string color):name{name}, model{model}, year{year}, color{color} {

}

string Car::getName() {
    return this->name;
}

string Car::getModel() {
    return this->model;
}

int Car::getYear() {
    return this->year;
}

string Car::getColor() {
    return this->color;
}

Car::~Car() {

}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, Car &c) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, '|');
    if (tokens.size() != 4)
        return is;
    c.name = tokens[0];
    c.model = tokens[1];
    c.year = stoi(tokens[2]);
    c.color = tokens[3];
    return is;
}

bool Car::operator==(Car &c) {
    if (this->name == c.name && this->model == c.model && this->year == c.year && this->color == c.color)
        return true;
    return false;
}
