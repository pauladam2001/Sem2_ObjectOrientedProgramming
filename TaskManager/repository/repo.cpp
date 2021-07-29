//
// Created by paula on 5/20/2021.
//

#include "repo.h"
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->data = this->load_data();
}

vector<Task> Repository::getData() {
    return this->data;
}

vector<Task> Repository::load_data() {
    std::ifstream inFile(R"(C:\Users\paula\CLionProjects\OOP\Task Manager\tasks.txt)");
    Task currentTask;
    vector<Task> all_entries;
    while (inFile >> currentTask)
        all_entries.push_back(currentTask);
    inFile.close();
    return all_entries;
}

Repository::~Repository() {

}
