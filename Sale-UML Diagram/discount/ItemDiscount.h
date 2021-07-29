//
// Created by paula on 6/18/2021.
//

#ifndef SALE_UML_DIAGRAM_WRITTEN_ITEMDISCOUNT_H
#define SALE_UML_DIAGRAM_WRITTEN_ITEMDISCOUNT_H

#include "Discount.h"


class ItemDiscount : public Discount {
private:
    int code;
    int percentage;
public:
    ItemDiscount(int code, int percentage);

    double calc(Sale s) override;
};


#endif //SALE_UML_DIAGRAM_WRITTEN_ITEMDISCOUNT_H
