//
// Created by paula on 5/20/2021.
//

#include "repo.h"
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->data = this->load_data();
}

vector<Vegetable> Repository::getData() {
    return this->data;
}

vector<Vegetable> Repository::load_data() {
    std::ifstream inFile(R"(C:\Users\paula\CLionProjects\OOP\Vegetables\vegetables.txt)");
    Vegetable currentVegetable;
    vector<Vegetable> all_entries;
    while (inFile >> currentVegetable)
        all_entries.push_back(currentVegetable);
    inFile.close();
    return all_entries;
}

Repository::~Repository() {

}
