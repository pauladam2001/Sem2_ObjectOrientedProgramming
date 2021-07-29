//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_TEACHER_H
#define BACHELOR_THESES_TEACHER_H

#include <string>
#include <sstream>

using namespace std;


class Teacher {
private:
    string name;

public:
    Teacher() = default;

    Teacher(string name);

    string getName();

    friend istream& operator>>(istream&, Teacher&);

    ~Teacher() = default;
};


#endif //BACHELOR_THESES_TEACHER_H
