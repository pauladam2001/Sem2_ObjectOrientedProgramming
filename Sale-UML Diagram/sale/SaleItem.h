//
// Created by paula on 6/18/2021.
//

#ifndef SALE_UML_DIAGRAM_WRITTEN_SALEITEM_H
#define SALE_UML_DIAGRAM_WRITTEN_SALEITEM_H


class SaleItem {
private:
    int code;
    double price;

public:
    SaleItem(int code, double price);

    int getCode() const;

    double getPrice() const;

    void setPrice(double pricee);
};


#endif //SALE_UML_DIAGRAM_WRITTEN_SALEITEM_H
