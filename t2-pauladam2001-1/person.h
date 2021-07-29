//
// Created by paula on 4/26/2021.
//

#ifndef T2_PAULADAM2001_1_PERSON_H
#define T2_PAULADAM2001_1_PERSON_H

#include <string>
#include <vector>
#include "measurement.h"
#include "bp.h"
#include "bmi.h"

using namespace std;

class Person {
private:
    string name;
    vector<Measurement*> data;
    Measurement* absMeasurement;

public:
    Person(string name);

    void init_person();

    string getName();

    int addMeasurement(Measurement* a);

    int add_BMI_from_ui(string date, double value);

    int add_BP_from_ui(string date, int systolic, int diastolic);

    vector<Measurement*> getAllMeasurements();

    vector<Measurement*> getMeasurementsByMonth(int month);

    bool isHealty(int month);

    vector<Measurement*> getMeasurementsNewerThan(string date);

    void writeToFile(string filename, string date);

    ~Person();
};


#endif //T2_PAULADAM2001_1_PERSON_H
