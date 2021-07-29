//
// Created by paula on 6/18/2021.
//

#include "beverages.h"
#include <iostream>


Beverage::Beverage(string description): description{std::move(description)} {

}

void Beverage::print() {
    cout << "Description: " << this->description << ", price: " << this->price() << "\n";
}

string Beverage::getDescription() {
    return this->description;
}



Coffee::Coffee(): Beverage("Coffee") {

}

double Coffee::price() {
    return 2.5;
}



Tea::Tea(): Beverage("Tea") {

}

double Tea::price() {
    return 1.5;
}



void BeverageMachine::prepare(const string& beverageType, int milkCount) {
    Beverage* newBeverage;
    if (beverageType == "Coffee")
        newBeverage = new Coffee();
    else if (beverageType == "Tea")
        newBeverage = new Tea();
    else {
        cout << "Invalid beverage type!";
        return;
    }
    if (milkCount == 0)
        newBeverage->print();
    else {
        BeverageWithMilk beverageWithMilk(milkCount, newBeverage);
        beverageWithMilk.print();
    }
    delete newBeverage;
}



BeverageWithMilk::BeverageWithMilk(int milkCount, Beverage* beverage):Beverage(beverage->getDescription()), milkCount{milkCount}, beverage{beverage} {

}

double BeverageWithMilk::price() {
    return (0.5 * this->milkCount) + beverage->price();
}

void BeverageWithMilk::print() {
    this->beverage->print();
    cout << this->milkCount << " portions of milk were added and the price is now " << this->price() << "\n";
}
