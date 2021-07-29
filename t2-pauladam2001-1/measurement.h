//
// Created by paula on 4/26/2021.
//

#ifndef T2_PAULADAM2001_1_MEASUREMENT_H
#define T2_PAULADAM2001_1_MEASUREMENT_H

#include <string>

using namespace std;


class Measurement {
protected:
    string date;

public:
//    Measurement(string date);

    virtual bool isNormalValue() = 0;

    virtual string toString() = 0;

    virtual string type() = 0;

    virtual ~Measurement() = default;
};


#endif //T2_PAULADAM2001_1_MEASUREMENT_H
