//
// Created by paula on 5/20/2021.
//

#include "bill.h"
#include <sstream>
#include <iostream>

Bill::Bill() {

}

Bill::Bill(string company, string code, double sum, string isPaid): company{company}, code{code}, sum{sum}, isPaid{isPaid} {

}

string Bill::getCompany() {
    return this->company;
}

string Bill::getCode() {
    return this->code;
}

double Bill::getSum() {
    return this->sum;
}

string Bill::getIsPaid() {
    return this->isPaid;
}

Bill::~Bill() {

}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, Bill &b) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ';');
    if (tokens.size() != 4)
        return is;
    b.company = tokens[0];
    b.code = tokens[1];
    b.sum = stod(tokens[2]);
    b.isPaid = tokens[3];
    return is;
}
