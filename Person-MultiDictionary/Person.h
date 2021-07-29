//
// Created by paula on 6/18/2021.
//

#ifndef PERSON_MULTIDICTIONARY_WRITTEN_PERSON_H
#define PERSON_MULTIDICTIONARY_WRITTEN_PERSON_H

#include <string>

using namespace std;


class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age);

    friend std::ostream& operator <<(std::ostream& output, const Person& person);
};


#endif //PERSON_MULTIDICTIONARY_WRITTEN_PERSON_H
