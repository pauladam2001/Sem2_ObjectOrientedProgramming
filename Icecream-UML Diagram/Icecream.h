//
// Created by paula on 6/18/2021.
//

#ifndef ICECREAM_UML_DIAGRAM_WRITTEN_ICECREAM_H
#define ICECREAM_UML_DIAGRAM_WRITTEN_ICECREAM_H

#include <string>

using namespace std;


class Icecream {
public:
    virtual string getDescription() = 0;

    virtual double computePrice() = 0;

    virtual ~Icecream() = default;
};


#endif //ICECREAM_UML_DIAGRAM_WRITTEN_ICECREAM_H
