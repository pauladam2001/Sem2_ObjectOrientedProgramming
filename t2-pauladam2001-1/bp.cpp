//
// Created by paula on 4/26/2021.
//

#include "bp.h"
#include <sstream>
#include <iomanip>


BP::BP(string date, int systolic, int diastolic) {
    this->date = date;
    this->systolicValue = systolic;
    this->diastolicValue = diastolic;
}

bool BP::isNormalValue() {
    if (this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <= 79)
        return true;
    return false;
}

string BP::toString() {
    stringstream buffer;

    buffer << "BP" << "  | " << setw(24) << right << "Systolic: " << this->systolicValue << setw(20) << right << "Diastolic:" << this->diastolicValue << endl;
    return buffer.str();
}

string BP::type() {
    stringstream buffer;

    buffer << "BP ";
    return buffer.str();
}

BP::~BP() = default;

