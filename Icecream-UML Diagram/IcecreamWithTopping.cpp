//
// Created by paula on 6/18/2021.
//

#include "IcecreamWithTopping.h"


IcecreamWithTopping::IcecreamWithTopping(string description, double price): description{description}, price{price} {

}

string IcecreamWithTopping::getDescription() {
    return this->description + this->addTopping() + ", price";
}

double IcecreamWithTopping::computePrice() {
    if (this->addTopping() == "with chocolate topping")
        this->price += 3;
    else
        this->price += 2;
    return price;
}



string IcecreamWithChocolateTopping::addTopping() {
    return "with chocolate topping";
}

IcecreamWithChocolateTopping::IcecreamWithChocolateTopping(string description, double price): IcecreamWithTopping(description, price) {

}


string IcecreamWithCaramelTopping::addTopping() {
    return "with caramel topping";
}

IcecreamWithCaramelTopping::IcecreamWithCaramelTopping(string description, double price): IcecreamWithTopping(description, price) {

}
