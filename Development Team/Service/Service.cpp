//
// Created by paula on 6/20/2021.
//

#include "Service.h"


Service::Service(Repository &repo): repo{repo} {

}

vector<Issue> &Service::getIssues() {
    return this->repo.getIssues();
}

vector<Member> &Service::getMembers() {
    return this->repo.getMembers();
}

void Service::addIssue(string desc, string status, string reporter, string solver) {
    Issue i(desc, status, reporter, solver);
    this->repo.addIssue(i);
    this->notify();
}

void Service::deleteIssue(Issue i) {
    this->repo.deleteIssue(i);
    this->notify();
}

void Service::resolveIssue(Issue i, string name) {
    this->repo.resolveIssue(i, name);
    this->notify();
}

Service::~Service() = default;
