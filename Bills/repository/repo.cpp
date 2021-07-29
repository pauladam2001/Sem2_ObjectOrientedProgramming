//
// Created by paula on 5/20/2021.
//

#include "repo.h"
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->data = this->load_data();
}

vector<Bill> Repository::getData() {
    return this->data;
}

vector<Bill> Repository::load_data() {
    std::ifstream inFile(R"(C:\Users\paula\CLionProjects\OOP\Bills\bills.txt)");
    Bill currentBill;
    vector<Bill> all_entries;
    while (inFile >> currentBill)
        all_entries.push_back(currentBill);
    inFile.close();
    return all_entries;
}

Repository::~Repository() {

}
