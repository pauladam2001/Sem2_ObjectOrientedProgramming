//
// Created by paula on 5/24/2021.
//

#include "weather.h"
#include <sstream>
#include <iostream>

TimeInterval::TimeInterval() {

}

TimeInterval::TimeInterval(int start, int end, int prob, string desc): startHour{start}, endHour{end}, probability{prob}, description{desc} {

}

int TimeInterval::getStartHour() {
    return this->startHour;
}

int TimeInterval::getEndHour() {
    return this->endHour;
}

int TimeInterval::getProbability() {
    return this->probability;
}

string TimeInterval::getDescription() {
    return this->description;
}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, TimeInterval &t) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ';');
    if (tokens.size() != 4)
        return is;
    t.startHour = stoi(tokens[0]);
    t.endHour = stoi(tokens[1]);
    t.probability = stoi(tokens[2]);
    t.description = tokens[3];
    return is;
}

TimeInterval::~TimeInterval() {

}
