//
// Created by paula on 6/18/2021.
//

#ifndef ICECREAM_UML_DIAGRAM_WRITTEN_ICECREAMWITHTOPPING_H
#define ICECREAM_UML_DIAGRAM_WRITTEN_ICECREAMWITHTOPPING_H

#include "Icecream.h"
#include <string>

using namespace std;


class IcecreamWithTopping : public Icecream {
protected:
    string description;
    double price;
public:
    virtual string addTopping() = 0;

    IcecreamWithTopping(string description, double price);

    string getDescription() override;

    double computePrice() override;
};


class IcecreamWithChocolateTopping : public IcecreamWithTopping {
public:
    IcecreamWithChocolateTopping(string description, double price);

    string addTopping() override;
};


class IcecreamWithCaramelTopping : public IcecreamWithTopping {
public:
    IcecreamWithCaramelTopping(string description, double price);

    string addTopping() override;
};


#endif //ICECREAM_UML_DIAGRAM_WRITTEN_ICECREAMWITHTOPPING_H
