//
// Created by paula on 6/20/2021.
//

#include "RepoProgrammers.h"

RepoProgrammers::RepoProgrammers() {
    this->load_data();
}

void RepoProgrammers::load_data() {
    std::ifstream inFile("programmers.txt");
    Programmer currentProgrammer;
    this->programmers.clear();
    while (inFile >> currentProgrammer)
        this->programmers.push_back(currentProgrammer);
    inFile.close();
}

vector<Programmer> &RepoProgrammers::getAll() {
    return this->programmers;
}

