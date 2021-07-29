//
// Created by paula on 5/21/2021.
//

#include "item.h"
#include <sstream>
#include <iostream>

Item::Item() {

}

Item::Item(string category, string name, int quantity):category{category}, name{name}, quantity{quantity} {

}

string Item::getCategory() {
    return this->category;
}

string Item::getName() {
    return this->name;
}

int Item::getQuantity() {
    return this->quantity;
}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, Item &i) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, '|');
    if (tokens.size() != 3)
        return is;
    i.category = tokens[0];
    i.name = tokens[1];
    i.quantity = stoi(tokens[2]);
    return is;
}

Item::~Item() {

}
