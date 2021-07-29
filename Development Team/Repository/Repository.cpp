//
// Created by paula on 6/20/2021.
//

#include "Repository.h"


void Repository::load_data_issues() {
    std::ifstream inFile("issues.txt");
    Issue currentIssue;
    this->issues.clear();
    while (inFile >> currentIssue)
        this->issues.push_back(currentIssue);
}

void Repository::load_data_members() {
    std::ifstream inFile("members.txt");
    Member currentMember;
    this->members.clear();
    while (inFile >> currentMember)
        this->members.push_back(currentMember);
}

void Repository::save_issues_to_file() {
    std::ofstream outFile("issues.txt");
    for (const auto& currentIssue : this->issues)
        outFile << currentIssue << "\n";
}

Repository::Repository() {
    this->load_data_issues();
    this->load_data_members();
}

vector<Issue> &Repository::getIssues() {
    return this->issues;
}

vector<Member> &Repository::getMembers() {
    return this->members;
}

void Repository::addIssue(const Issue &i) {
    int pos = this->checkExistence(i);
    if (pos == -1) {
        this->issues.push_back(i);
        this->save_issues_to_file();
    }
    else
        throw exception();
}

int Repository::checkExistence(Issue i) {
    for (int index=0;index<this->issues.size();index++)
        if (this->issues[index].getDescription() == i.getDescription())
            return index;
    return -1;
}

void Repository::deleteIssue(const Issue &i) {
    int pos = this->checkExistence(i);
    if (pos != -1) {
        this->issues.erase(this->issues.begin() + pos);
        this->save_issues_to_file();
    }
    else
        throw exception();
}

void Repository::resolveIssue(const Issue &i, const string &name) {
    int pos = this->checkExistence(i);
    this->issues[pos].setStatus("closed");
    this->issues[pos].setSolver(name);
    this->save_issues_to_file();
}

Repository::~Repository() = default;
