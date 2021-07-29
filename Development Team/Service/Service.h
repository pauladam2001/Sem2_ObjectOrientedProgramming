//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_SERVICE_H
#define DEVELOPMENT_TEAM_SERVICE_H

#include "../Repository/Repository.h"
#include "../Observer/Observer.h"


class Service : public Observable {
private:
    Repository& repo;

public:
    Service(Repository& repo);

    vector<Issue>& getIssues();

    vector<Member>& getMembers();

    void addIssue(string desc, string status, string reporter, string solver);

    void deleteIssue(Issue i);

    void resolveIssue(Issue i, string name);

    ~Service();
};


#endif //DEVELOPMENT_TEAM_SERVICE_H
