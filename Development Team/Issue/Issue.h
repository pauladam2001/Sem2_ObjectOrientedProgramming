//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_ISSUE_H
#define DEVELOPMENT_TEAM_ISSUE_H

#include <string>

using namespace std;


class Issue {
private:
    string description;
    string status;
    string reporter;
    string solver;

public:
    Issue() = default;

    Issue(string d, string st, string r, string sol);

    string getDescription();

    string getStatus();

    string getReporter();

    string getSolver();

    void setStatus(string status);

    void setSolver(string solver);

    friend std::ostream& operator<<(std::ostream&, const Issue&);

    friend std::istream& operator>>(std::istream&, Issue&);
};


#endif //DEVELOPMENT_TEAM_ISSUE_H
