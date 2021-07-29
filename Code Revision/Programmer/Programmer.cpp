//
// Created by paula on 6/20/2021.
//

#include "Programmer.h"
#include <sstream>

Programmer::Programmer(string name, int nrRevisedFiles, int totalFiles): name{name}, nrRevisedFiles{nrRevisedFiles}, totalFiles{totalFiles} {

}

string Programmer::getName() {
    return this->name;
}

int Programmer::getNrRevisedFiles() {
    return this->nrRevisedFiles;
}

int Programmer::getTotalFiles() {
    return this->totalFiles;
}

void Programmer::setNrRevisedFiles(int number) {
    this->nrRevisedFiles = number;
}

istream &operator>>(istream &input, Programmer &p) {
    input>>p.name >> p.nrRevisedFiles >> p.totalFiles;
    return input;
}
