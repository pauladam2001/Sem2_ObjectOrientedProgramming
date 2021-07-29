//
// Created by Alexandra on 6/20/2021.
//

#include "UserRepo.h"
#include <fstream>

UserRepo::UserRepo() {
    this->LoadData();
}

UserRepo::~UserRepo() {

}

vector<User> &UserRepo::getUsers() {
    return this->users;
}

void UserRepo::LoadData() {
    ifstream inFile("users.txt");
    User currentElement;
    this->users.clear();
    while(inFile >> currentElement) {
        this->users.push_back(currentElement);
    }
    inFile.close();

}

