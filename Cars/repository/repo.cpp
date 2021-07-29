//
// Created by paula on 5/20/2021.
//

#include "repo.h"
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->data = this->load_data();
}

vector<Car> Repository::getData() {
    return this->data;
}

vector<Car> Repository::load_data() {
    std::ifstream inFile(R"(C:\Users\paula\CLionProjects\Cars\cars.txt)");
    Car currentCar;
    vector<Car> all_entries;
    while (inFile >> currentCar)
        all_entries.push_back(currentCar);
    inFile.close();
    return all_entries;
}

Repository::~Repository() {

}
