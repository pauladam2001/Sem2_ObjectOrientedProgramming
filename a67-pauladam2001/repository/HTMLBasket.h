//
// Created by paul on 4/12/2021.
//

#ifndef A67_PAULADAM2001_HTMLBASKET_H
#define A67_PAULADAM2001_HTMLBASKET_H

#include "AbstractBasket.h"
#include <string>


class HTMLShoppingBasket : public AbstractShoppingBasket {
private:

    string fileName;

public:

    HTMLShoppingBasket();

    void write() override;

    void open() override;

    void setData(std::vector<trenchCoat> dataToSet) override;

    ~HTMLShoppingBasket() override;
};


#endif //A67_PAULADAM2001_HTMLBASKET_H
