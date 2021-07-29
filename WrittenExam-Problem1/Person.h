//
// Created by paula on 6/22/2021.
//

#ifndef PROBLEM1_PERSON_H
#define PROBLEM1_PERSON_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age);

    friend std::ostream& operator <<(std::ostream& output, const Person& person);

    Person& operator =(const Person& person);

    bool operator ==(const Person& person) const;
};


#endif //PROBLEM1_PERSON_H
