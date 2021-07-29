//
// Created by paula on 5/20/2021.
//

#ifndef CARS_CAR_H
#define CARS_CAR_H

#include <string>
#include <vector>

using namespace std;

class Car {
private:
    string name;
    string model;
    int year;
    string color;

public:
    Car();

    Car(string name, string model, int year, string color);

    string getName();

    string getModel();

    int getYear();

    string getColor();

    friend std::istream& operator>>(std::istream&, Car&);

    bool operator==(Car&);

    ~Car();
};

#endif //CARS_CAR_H
