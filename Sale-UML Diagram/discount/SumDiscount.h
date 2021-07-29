//
// Created by paula on 6/18/2021.
//

#ifndef SALE_UML_DIAGRAM_WRITTEN_SUMDISCOUNT_H
#define SALE_UML_DIAGRAM_WRITTEN_SUMDISCOUNT_H

#include "Discount.h"
#include <vector>

using namespace std;


class SumDiscount : public Discount {
private:
    vector<Discount*> data;

public:
    SumDiscount();

    void add(Discount *d);

    double calc(Sale s) override;

};


#endif //SALE_UML_DIAGRAM_WRITTEN_SUMDISCOUNT_H
