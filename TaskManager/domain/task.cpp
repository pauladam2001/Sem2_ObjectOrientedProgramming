//
// Created by paula on 5/20/2021.
//

#include "task.h"
#include <sstream>
#include <iostream>

Task::Task() {

}

Task::Task(string description, int duration, int priority): description{description}, duration{duration}, priority{priority} {

}

string Task::getDescription() {
    return this->description;
}

int Task::getDuration() {
    return this->duration;
}

int Task::getPriority() {
    return this->priority;
}

Task::~Task() {

}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, Task &t) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, '|');
    if (tokens.size() != 3)
        return is;
    t.description = tokens[0];
    t.duration = stoi(tokens[1]);
    t.priority = stoi(tokens[2]);
    return is;
}
