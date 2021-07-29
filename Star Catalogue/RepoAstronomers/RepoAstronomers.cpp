//
// Created by paula on 6/20/2021.
//

#include "RepoAstronomers.h"

RepoAstronomers::RepoAstronomers() {
    this->LoadData();
}

vector<Astronomer>& RepoAstronomers::getAll() {
    return this->astronomers;
}

void RepoAstronomers::LoadData() {
    ifstream inFile("astronomers.txt");
    Astronomer currentElement;
    this->astronomers.clear();
    while(inFile >> currentElement){
        this->astronomers.push_back(currentElement);
    }
    inFile.close();
}

RepoAstronomers::~RepoAstronomers() = default;
