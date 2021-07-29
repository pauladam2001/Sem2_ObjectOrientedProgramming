//
// Created by paula on 4/26/2021.
//

#ifndef T2_PAULADAM2001_1_BP_H
#define T2_PAULADAM2001_1_BP_H

#include "measurement.h"
#include <string>

using namespace std;


class BP : public Measurement {
private:
    int systolicValue;
    int diastolicValue;

public:
    BP(string date, int systolic, int diastolic);

    bool isNormalValue() override;

    string toString() override;

    string type() override;

    ~BP() override;
};


#endif //T2_PAULADAM2001_1_BP_H
