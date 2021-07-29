//
// Created by paula on 6/18/2021.
//

#include "Order.h"
#include <iostream>

void Order::addIcecream(Icecream* i) {
    this->data.push_back(i);
}

void Order::printOrder() {
    for (int index = 0;index < this->data.size(); index++)
        cout << this->data[index]->getDescription() << ", price " << this->data[index]->computePrice() << "\n";
}
