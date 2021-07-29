//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include <string>
using namespace std;

class User {

private:
    string name;

public:
    User();
    User(string name);
    ~User();

    string getName();
    friend istream& operator>>(istream&, User&);

};

