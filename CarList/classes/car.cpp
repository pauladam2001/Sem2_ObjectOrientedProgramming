//
// Created by paula on 6/17/2021.
//

#include "car.h"

Car::Car(string name, int number): name{name}, number{number} {

}

string Car::getName() {
    return this->name;
}

int Car::getNumber() {
    return this->number;
}
