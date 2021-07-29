//
// Created by paula on 6/18/2021.
//

#include "SimpleIceCream.h"


SimpleIcecream::SimpleIcecream(string description, double price): description{std::move(description)}, price{price} {

}

string SimpleIcecream::getDescription() {
    return "Simple ice cream with " + this->description;
}

double SimpleIcecream::computePrice() {
    return this->price;
}

std::ostream &operator<<(ostream &output, const SimpleIcecream &i) {
//    output << "aaa";
//    return output;
}
