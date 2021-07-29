//
// Created by paula on 4/26/2021.
//

#ifndef T2_PAULADAM2001_1_BMI_H
#define T2_PAULADAM2001_1_BMI_H

#include "measurement.h"
#include <string>

using namespace std;


class BMI : public Measurement {
private:
    double value;

public:
    BMI(string date, double value);

    bool isNormalValue() override;

    string toString() override;

    string type() override;

    ~BMI() override;
};


#endif //T2_PAULADAM2001_1_BMI_H
