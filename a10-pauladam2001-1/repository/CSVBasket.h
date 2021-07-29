//
// Created by paul on 4/12/2021.
//

#ifndef A67_PAULADAM2001_CSVBASKET_H
#define A67_PAULADAM2001_CSVBASKET_H

#include "AbstractBasket.h"


class CSVShoppingBasket : public AbstractShoppingBasket {
private:

    string fileName;

public:

    CSVShoppingBasket();

    void write() override;

    void open() override;

    void setData(std::vector<trenchCoat> dataToSet) override;

    ~CSVShoppingBasket() override;
};


#endif //A67_PAULADAM2001_CSVBASKET_H
