//
// Created by paula on 6/18/2021.
//

#ifndef ICECREAM_UML_DIAGRAM_WRITTEN_SIMPLEICECREAM_H
#define ICECREAM_UML_DIAGRAM_WRITTEN_SIMPLEICECREAM_H

#include "Icecream.h"
#include <string>

using namespace std;


class SimpleIcecream : public Icecream{
private:
    string description;
    double price;

public:
    SimpleIcecream(string description, double price);

    string getDescription() override;

    double computePrice() override;

    friend std::ostream& operator <<(std::ostream& output, const SimpleIcecream& i);
};


#endif //ICECREAM_UML_DIAGRAM_WRITTEN_SIMPLEICECREAM_H
