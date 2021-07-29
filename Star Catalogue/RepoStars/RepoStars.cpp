//
// Created by paula on 6/20/2021.
//

#include "RepoStars.h"

RepoStars::RepoStars() {
    this->LoadData();
}

vector<Star>& RepoStars::getAll() {
    return this->stars;
}

void RepoStars::LoadData() {
    ifstream inFile("stars.txt");
    Star currentElement;
    this->stars.clear();
    while(inFile >> currentElement){
        this->stars.push_back(currentElement);
    }
}

vector<Star> RepoStars::filterStarsByConstellation(string constellation) {
    vector<Star> filtered;
    for(auto & s: this->getAll()){
        if(s.getConstellation() == constellation){
            filtered.push_back(s);
        }
    }
    return filtered;
}

vector<Star> RepoStars::filterStarsByName(string name) {
    vector<Star> filtered;
    for(auto & s: this->getAll()){
        if(s.getName().find(name)!=std::string::npos)
        {
            filtered.push_back(s);
        }
    }
    return filtered;
}

void RepoStars::addStar(const Star& s) {
    this->stars.push_back(s);
    this->saveToFile();
    this->notify();
}

void RepoStars::saveToFile() {
    ofstream OutFile("stars.txt");
    vector<Star> sorted(this->stars);
    for(int i = 0; i < sorted.size()-1; i++){
        for(int j=i+1; j< sorted.size(); j++){
            if(sorted[i].getName()>sorted[j].getName()){
                swap(sorted[i], sorted[j]);
            }
        }
    }
    for(auto & s: sorted){
        OutFile<<s<<'\n';
    }
}

RepoStars::~RepoStars() = default;
