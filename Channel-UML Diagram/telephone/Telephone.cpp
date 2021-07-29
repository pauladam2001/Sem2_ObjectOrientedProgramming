//
// Created by paula on 6/18/2021.
//

#include <iostream>
#include <ctime>
#include "Telephone.h"
#include <stdexcept>

using namespace std;


void Telephone::send(string message) {
    srand(time(nullptr));
    int r = rand() % 10;
    if (r == 7) { // telephone
        throw runtime_error("Telephone line is busy!");
    }
    else
        cout << "Dialing " << this->number << "\n";
}

void Fax::send(string message) {
    srand(time(nullptr));
    int r = rand() % 10;
    if (r == 8) // fax
        throw runtime_error("Fax line is busy!");

    cout << "Sending fax \n";
}

void SMS::send(string message) {
    cout << "Sending SMS \n";
}
