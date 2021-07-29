//
// Created by paula on 6/17/2021.
//

#ifndef CAR_LIST_WRITTEN_CAR_H
#define CAR_LIST_WRITTEN_CAR_H

#include <string>

using namespace std;


class Car {
private:
    string name;
    int number;

public:
    Car(string name, int number);

    string getName();

    int getNumber();

};


#endif //CAR_LIST_WRITTEN_CAR_H
