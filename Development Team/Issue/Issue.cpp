//
// Created by paula on 6/20/2021.
//

#include "Issue.h"
#include <sstream>


Issue::Issue(string d, string st, string r, string sol): description{d}, status{st}, reporter{r}, solver{sol} {

}

string Issue::getDescription() {
    return this->description;
}

string Issue::getStatus() {
    return this->status;
}

string Issue::getReporter() {
    return this->reporter;
}

string Issue::getSolver() {
    return this->solver;
}

void Issue::setStatus(string status) {
    this->status = status;
}

void Issue::setSolver(string solver) {
    this->solver = solver;
}

std::ostream &operator<<(ostream &output, const Issue &i) {
    output << i.description << " " << i.status << " " << i.reporter << " " << i.solver;
    return output;
}

std::istream &operator>>(istream &input, Issue &i) {
    input >> i.description >> i.status >> i.reporter >> i.solver;
    return input;
}
