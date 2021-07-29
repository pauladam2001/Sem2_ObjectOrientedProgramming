//
// Created by paula on 4/26/2021.
//

#include "person.h"
#include <fstream>

Person::Person(string name) {
    this->name = name;
}

void Person::init_person() {
    Measurement* a = new BP("2021.05.27", 91, 63);
    this->addMeasurement(a);
    Measurement* b = new BP("2021.04.26", 89, 70);
    this->addMeasurement(b);
    Measurement* c = new BMI("2021.08.30", 20);
    this->addMeasurement(c);
    Measurement* d = new BP("2021.07.07", 80, 100);
    this->addMeasurement(d);
    Measurement* e = new BMI("2021.03.05", 33);
    this->addMeasurement(e);
}

int Person::addMeasurement(Measurement* a) {
    this->absMeasurement = a;
    this->data.push_back(this->absMeasurement);
    if (this->absMeasurement->isNormalValue() == true)
        return 1;
    return 0;
}

vector<Measurement *> Person::getAllMeasurements() {
    return this->data;
}

bool Person::isHealty(int month) {
    ;
}

void Person::writeToFile(string filename, string date) {
    std::ofstream outFile("C:\\Users\\paula\\OneDrive\\Documents\\GitHub\\t2-pauladam2001-1\\a.txt");
//    std::ofstream outFile(filename);
    for (const auto& current: this->data) {
        int i = 0;
        while (i != '.')
            i++;
        outFile << current->type() << current->toString() << "\n";
    }
    outFile.close();
}

Person::~Person() {
    delete this->absMeasurement;
}

int Person::add_BMI_from_ui(string date, double value) {
    Measurement* bmi = new BMI(date, value);
    return this->addMeasurement(bmi);
}

int Person::add_BP_from_ui(string date, int systolic, int diastolic) {
    Measurement* bp = new BP(date, systolic, diastolic);
    return this->addMeasurement(bp);
}

string Person::getName() {
    return this->name;
}
