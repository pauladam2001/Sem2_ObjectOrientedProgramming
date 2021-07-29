//
// Created by paula on 6/18/2021.
//

#include "SumDiscount.h"

SumDiscount::SumDiscount() = default;

void SumDiscount::add(Discount *d) {
    this->data.push_back(d);
}

double SumDiscount::calc(Sale s) {
    double totalSum = 0;
    for (auto& elem : this->data) {
           double sum = elem->calc(s);
           totalSum += sum;
    }
    return totalSum;
}
