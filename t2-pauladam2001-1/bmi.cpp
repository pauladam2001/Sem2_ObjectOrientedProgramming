//
// Created by paula on 4/26/2021.
//

#include "bmi.h"
#include <sstream>
#include <iomanip>

BMI::BMI(string date, double value) {
    this->date = date;
    this->value = value;
}

bool BMI::isNormalValue() {
    if (this->value >= 18.5 && this->value <= 25)
        return true;
    return false;
}

string BMI::toString() {
    stringstream buffer;

    buffer << "BMI" << " | " << setw(20) << right << "Value:" << this->value << endl;
    return buffer.str();
}

string BMI::type() {
    stringstream buffer;

    buffer << "BMI ";
    return buffer.str();
}

BMI::~BMI() = default;
