//
// Created by paula on 5/21/2021.
//

#include "repo.h"
#include <fstream>
#include <iostream>

Repository::Repository() {
    this->data = this->load_data();
}

vector<Item> Repository::getData() {
    return this->data;
}

vector<Item> Repository::load_data() {
    std::ifstream inFile(R"(C:\Users\paula\CLionProjects\OOP\Shopping List\list.txt)");
    Item currentItem;
    vector<Item> all_entries;
    while (inFile >> currentItem)
        all_entries.push_back(currentItem);
    inFile.close();
    return all_entries;
}

void Repository::delete_item(string category, string name) {
    int pos = this->search_in_repo(category, name);
    if (pos != -1)
        this->data.erase(this->data.begin() + pos);
}

Repository::~Repository() {

}

int Repository::search_in_repo(string category, string name) {
    int index = 0;
    for (auto& element : this->data) {
        if (element.getCategory() == category && element.getName() == name)
            break;
        index++;
    }
    if (index == this->data.size())
        return -1;
    return index;
}
