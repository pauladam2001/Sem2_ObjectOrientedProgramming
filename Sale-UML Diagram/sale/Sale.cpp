//
// Created by paula on 6/18/2021.
//

#include "Sale.h"

Sale::Sale() = default;

vector<SaleItem> Sale::getData() {
    return this->data;
}

void Sale::add(SaleItem si) {
    this->data.push_back(si);
}
