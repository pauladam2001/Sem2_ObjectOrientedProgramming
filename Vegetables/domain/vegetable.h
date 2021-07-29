//
// Created by paula on 5/20/2021.
//

#ifndef CARS_TASK_H
#define CARS_TASK_H

#include <string>
#include <vector>

using namespace std;

class Vegetable {
private:
    string family;
    string name;
    string parts;

public:
    Vegetable();

    Vegetable(string family, string name, string parts);

    string getFamily();

    string getName();

    string getParts();

    friend std::istream& operator>>(std::istream&, Vegetable&);

    ~Vegetable();
};

#endif //CARS_TASK_H
