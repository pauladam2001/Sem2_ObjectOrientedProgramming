//
// Created by paula on 5/24/2021.
//

#include "repo.h"
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->data = this->load_data();
}

vector<TimeInterval> Repository::getData() {
    return this->data;
}

vector<TimeInterval> Repository::load_data() {
    std::ifstream inFile(R"(C:\Users\paula\OneDrive\Documents\GitHub\t3-pauladam2001\input.txt)");
    TimeInterval currentWeather;
    vector<TimeInterval> all_entries;
    while (inFile >> currentWeather)
        all_entries.push_back(currentWeather);
    inFile.close();
    return all_entries;
}

Repository::~Repository() {

}
