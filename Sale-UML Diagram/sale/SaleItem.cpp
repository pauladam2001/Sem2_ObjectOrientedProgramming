//
// Created by paula on 6/18/2021.
//

#include "SaleItem.h"

SaleItem::SaleItem(int code, double price): code{code}, price{price} {

}

int SaleItem::getCode() const {
    return this->code;
}

double SaleItem::getPrice() const {
    return this->price;
}

void SaleItem::setPrice(double pricee) {
    this->price = pricee;
}
