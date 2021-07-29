//
// Created by paula on 6/22/2021.
//

#include "Building.h"

Building::Building(int id, string description, string area, vector<string> locations): id{id}, description{description}, area{area}, locations{locations} {

}

int Building::getId() {
    return this->id;
}

string Building::getDescription() {
    return this->description;
}

string Building::getArea() {
    return this->area;
}

vector<string> &Building::getLocations() {
    return this->locations;
}

void Building::setDescription(string description) {
    this->description = description;
}

void Building::setLocation(vector<string> locations) {
    this->locations = locations;
}

vector<string> Building::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream &operator>>(istream &input, Building &b) {
    string line;
    getline(input, line);
    vector<string> tokens = Building::tokenize(line, ';');
    if (tokens.size() != 4)
        return input;

    b.id = stoi(tokens[0]);
    b.description = tokens[1];
    b.area = tokens[2];

    vector<string> tokensCoordinates = Building::tokenize(tokens[3], ',');

    b.locations.clear();

    for (auto &e : tokensCoordinates)
        b.locations.push_back(e);

    tokensCoordinates.clear();

    return input;
}
