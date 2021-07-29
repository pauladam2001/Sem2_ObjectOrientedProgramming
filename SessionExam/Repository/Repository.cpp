//
// Created by paula on 6/22/2021.
//

#include "Repository.h"

Repository::Repository() {
    this->load_data_ethnologists();
    this->load_data_buildings();
    this->load_data_ethnologists();
}

void Repository::load_data_ethnologists() {
    ifstream inFile(R"(C:\Users\paula\OneDrive\Documents\GitHub\e2-pauladam2001-1\ethnologists.txt)");
    Ethnologist currentElement;
    this->ethnologists.clear();
    while(inFile >> currentElement) {
        this->ethnologists.push_back(currentElement);
    }
    inFile.close();
}

void Repository::load_data_buildings() {
    ifstream inFile(R"(C:\Users\paula\OneDrive\Documents\GitHub\e2-pauladam2001-1\buildings.txt)");
    Building currentElement;
    this->ethnologists.clear();
    while(inFile >> currentElement) {
        this->buildings.push_back(currentElement);
    }
    inFile.close();
}

vector<Ethnologist> &Repository::getEthnologists() {
    return this->ethnologists;
}

vector<Building> &Repository::getBuildings() {
    return this->buildings;
}

void Repository::add_building(Building building) {
    this->buildings.push_back(building);
}

void Repository::update_building(int id, string decription, vector<string> locations) {
    for (auto &b : this->buildings)
        if (b.getId() == id) {
            b.setDescription(decription);
            b.setLocation(locations);
        }
}
