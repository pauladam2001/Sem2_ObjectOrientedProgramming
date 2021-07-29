//
// Created by paula on 6/18/2021.
//

#ifndef SALE_UML_DIAGRAM_WRITTEN_SALE_H
#define SALE_UML_DIAGRAM_WRITTEN_SALE_H

#include <vector>
#include "SaleItem.h"

using namespace std;


class Sale {
private:
    vector<SaleItem> data;

public:
    Sale();

    vector<SaleItem> getData();

    void add(SaleItem si);
};


#endif //SALE_UML_DIAGRAM_WRITTEN_SALE_H
