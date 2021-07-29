//
// Created by paula on 4/12/2021.
//

#ifndef A67_PAULADAM2001_ABSTRACTBASKET_H
#define A67_PAULADAM2001_ABSTRACTBASKET_H

#include <vector>
#include "trenchCoat.h"


class AbstractShoppingBasket {
protected:

    std::vector<trenchCoat> data;

public:

    virtual void write() = 0;

    virtual void open() = 0;

    virtual void setData(std::vector<trenchCoat> dataToSet) = 0;

    virtual ~AbstractShoppingBasket() = default;
};


#endif //A67_PAULADAM2001_ABSTRACTBASKET_H
