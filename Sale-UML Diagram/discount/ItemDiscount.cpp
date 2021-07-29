//
// Created by paula on 6/18/2021.
//

#include "ItemDiscount.h"

ItemDiscount::ItemDiscount(int code, int percentage):code{code}, percentage{percentage} {

}

double ItemDiscount::calc(Sale s) {
    double totalDiscount = 0;
    for (auto& elem : s.getData()) {
        if (this->code == elem.getCode()) {
            double discount = (this->percentage * elem.getPrice()) / 100;
            totalDiscount += discount;
            double newPrice = elem.getPrice() - discount;
            elem.setPrice(newPrice);
        }
    }
    return totalDiscount;
}
