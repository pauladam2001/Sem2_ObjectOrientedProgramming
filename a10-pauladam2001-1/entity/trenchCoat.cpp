//
// Created by paul on 3/20/2021.
//

#include "trenchCoat.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <sstream>


trenchCoat::trenchCoat() = default;

trenchCoat::trenchCoat(const string& size, const string& color, int price, int quantity, const string& photograph):size{size}, color{color}, price{price}, quantity{quantity}, photograph{photograph} {
}

string trenchCoat::getSize() const {
    return this->size;
}

string trenchCoat::getColor() const {
    return this->color;
}

int trenchCoat::getPrice() const {
    return this->price;
}

int trenchCoat::getQuantity() const {
    return this->quantity;
}

string trenchCoat::getPhotograph() const {
    return this->photograph;
}

//void trenchCoat::setPrice(int value) {
//    this->price = value;
//}
//
//void trenchCoat::setQuantity(int value) {
//    this->quantity = value;
//}

void trenchCoat::to_string(char stringParam[]) {        //OR with stringstream
    sprintf(stringParam, "Size:%s, Color:%s, Price:%d, Quantity:%d, Photograph:%s", this->size.c_str(), this->color.c_str(), this->price, this->quantity, this->photograph.c_str());

    // OR with stringstream

//    stringstream buffer;
//    buffer << setw(20) << left << this->size << "|   " << setw(20) << left << this->color << "|   " << setw(20) << right << this->price << this->quantity << this->photograph;
//    return buffer.str();
}

trenchCoat::trenchCoat(const trenchCoat &c):size{c.size}, color{c.color}, price{c.price}, quantity{c.quantity}, photograph{c.photograph} {

}

trenchCoat &trenchCoat::operator=(const trenchCoat &c) {        //OR without nothing in function and = default; (see warning)
    this->size = c.size;
    this->color = c.color;
    this->price = c.price;
    this->quantity = c.quantity;
    this->photograph = c.photograph;
    return *this;
}

bool trenchCoat::operator==(const trenchCoat &c) const {
    if (this->size == c.size && this->color == c.color && this->photograph == c.photograph)
        return true;
    return false;
}

//std::ostream &operator<<(ostream &os, const trenchCoat &c) {
//    os<<c.size<<" "<<c.color<<" "<<c.price<<" "<<c.quantity<<" "<<c.photograph;
//    return os;
//}

//std::istream &operator>>(istream &is, trenchCoat &c) {
//    is>>c.size>>c.color>>c.price>>c.quantity>>c.photograph;
//    return is;
//}

std::ostream &operator<<(ostream &os, const trenchCoat &c) {
    os<<c.size<<","<<c.color<<","<<c.price<<","<<c.quantity<<","<<c.photograph;
    return os;
}

vector<string> tokenize(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(istream &is, trenchCoat &c) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)                               // if we want to delimit by something different than space
        return is;
    c.size = tokens[0];
    c.color = tokens[1];
    c.price = stoi(tokens[2]);
    c.quantity = stoi(tokens[3]);
    c.photograph = tokens[4];

    return is;
}

std::string trenchCoat::getCSVRepresentation() {
    stringstream trenchCoatRepr;
    trenchCoatRepr << this->size << "," << this->color << "," << this->price << "," << this->quantity << "," << this->photograph;
    return trenchCoatRepr.str();
}

std::string trenchCoat::getHTMLRepresentation() {
    stringstream trenchCoatRepr;
    trenchCoatRepr << "\t<tr>\n" << "\t\t<td>" << this->size << "</td>\n" << "\t\t<td>" << this->color << "</td>\n" << "\t\t<td>" << this->price << "</td\n>" << "\t\t<td>" << this->quantity << "</td>\n" << "\t\t<td><a href=" << this->photograph << ">Link</a></td>\n" << "\t</tr>\n";
    return trenchCoatRepr.str();
}

trenchCoat::~trenchCoat() = default;
