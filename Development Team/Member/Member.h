//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_MEMBER_H
#define DEVELOPMENT_TEAM_MEMBER_H

#include <string>

using namespace std;


class Member {
    string name;
    string type;

public:
    Member() = default;

    Member(string name, string type);

    string getName();

    string getType();

    friend std::istream& operator>>(std::istream&, Member&);
};


#endif //DEVELOPMENT_TEAM_MEMBER_H
