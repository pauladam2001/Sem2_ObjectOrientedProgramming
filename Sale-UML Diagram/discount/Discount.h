//
// Created by paula on 6/18/2021.
//

#ifndef SALE_UML_DIAGRAM_WRITTEN_DISCOUNT_H
#define SALE_UML_DIAGRAM_WRITTEN_DISCOUNT_H

#include "../sale/Sale.h"


class Discount {
public:
    virtual double calc(Sale s) = 0;

    virtual ~Discount() = default;
};


#endif //SALE_UML_DIAGRAM_WRITTEN_DISCOUNT_H
