//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_REPOSITORY_H
#define DEVELOPMENT_TEAM_REPOSITORY_H

#include <vector>
#include "../Issue/Issue.h"
#include "../Member/Member.h"
#include <fstream>
#include <string>

using namespace std;


class Repository {
private:
    vector<Issue> issues;
    vector<Member> members;

    void load_data_issues();

    void load_data_members();

    void save_issues_to_file();

public:
    Repository();

    vector<Issue>& getIssues();

    vector<Member>& getMembers();

    void addIssue(const Issue& i);

    int checkExistence(Issue i);

    void deleteIssue(const Issue& i);

    void resolveIssue(const Issue& i, const string& name);

    ~Repository();
};


#endif //DEVELOPMENT_TEAM_REPOSITORY_H
