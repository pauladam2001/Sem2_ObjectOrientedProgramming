//
// Created by paula on 4/5/2021.
//

#include "gene.h"
#include <string>
#include <cstdio>
#include <iomanip>
#include <sstream>


Gene::Gene() = default;

Gene::Gene(string organism, string name, string sequence): organism{organism}, name{name}, sequence{sequence} {

}

string Gene::getOrganism() {
    return this->organism;
}

string Gene::getName() {
    return this->name;
}

string Gene::getSequence() {
    return this->sequence;
}

string Gene::to_string() {
//    sprintf(stringParam, "Organism:%s | Name:%s | Sequence:%s", this->organism.c_str(), this->name.c_str(), this->sequence.c_str());
    stringstream buffer;
    buffer << setw(20) << left << this->organism << "|   " << setw(20) << left << this->name << "|   " << setw(20) << right << this->sequence;
    return buffer.str();
}

Gene::~Gene() = default;
