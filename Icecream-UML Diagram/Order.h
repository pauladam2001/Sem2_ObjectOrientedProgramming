//
// Created by paula on 6/18/2021.
//

#ifndef ICECREAM_UML_DIAGRAM_WRITTEN_ORDER_H
#define ICECREAM_UML_DIAGRAM_WRITTEN_ORDER_H

#include "Icecream.h"
#include <vector>

using namespace std;


class Order {
private:
    vector<Icecream*> data;

public:
    Order() = default;

    void addIcecream(Icecream* i);

    void printOrder();

    ~Order() = default;
};


#endif //ICECREAM_UML_DIAGRAM_WRITTEN_ORDER_H
