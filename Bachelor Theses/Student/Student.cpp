//
// Created by paula on 6/21/2021.
//

#include "Student.h"

Student::Student(string id, string name, string email, int year, string title, string coordinator): id{id}, name{name}, email{email}, year{year}, title{title},coordinator{coordinator} {

}

string Student::getId() {
    return this->id;
}

string Student::getName() {
    return this->name;
}

string Student::getEmail() {
    return this->email;
}

int Student::getYear() {
    return this->year;
}

string Student::getTitle() {
    return this->title;
}

string Student::getCoordinator() {
    return this->coordinator;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setTitle(string title) {
    this->title = title;
}

void Student::setCoordinator(string coordinator) {
    this->coordinator = coordinator;
}

vector<string> Student::tokenize(const string &str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream &operator>>(istream &input, Student &s) {
    string line;
    getline(input, line);

    vector<string> tokens = Student::tokenize(line, ',');
    if (tokens.size() < 5)
        return input;
    if(tokens.size() == 5) {
        s.id = tokens[0];
        s.name = tokens[1];
        s.email = tokens[2];
        s.year = stoi(tokens[3]);
        s.title = tokens[4];
        s.coordinator = "";
    }
    else {
        s.id = tokens[0];
        s.name = tokens[1];
        s.email = tokens[2];
        s.year = stoi(tokens[3]);
        s.title = tokens[4];
        s.coordinator = tokens[5];
    }

    return input;
}

bool Student::operator==(const Student &s) {
    if(this->name == s.name && this->id == s.id && this->email == s.email && this->year == s.year && this->coordinator == s.coordinator){
        return true;
    }
    return false;
}
