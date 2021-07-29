//
// Created by paul on 3/20/2021.
//

#include "trenchCoat.h"
#include <string>
#include <cstdio>


trenchCoat::trenchCoat() {

}

trenchCoat::trenchCoat(string size, string color, int price, int quantity, string photograph) {
    this->size = size;
    this->color = color;
    this->price = price;
    this->quantity = quantity;
    this->photograph = photograph;
}

string trenchCoat::getSize() {
    return this->size;
}

string trenchCoat::getColor() {
    return this->color;
}

int trenchCoat::getPrice() {
    return this->price;
}

int trenchCoat::getQuantity() {
    return this->quantity;
}

string trenchCoat::getPhotograph() {
    return this->photograph;
}

void trenchCoat::to_string(char stringParam[]) {        //OR with stringstream
    sprintf(stringParam, "Size:%s, Color:%s, Price:%d, Quantity:%d, Photograph:%s", this->size.c_str(), this->color.c_str(), this->price, this->quantity, this->photograph.c_str());
}

trenchCoat::~trenchCoat() {

}
