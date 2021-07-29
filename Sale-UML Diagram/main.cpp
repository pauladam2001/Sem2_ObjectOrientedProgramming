#include <iostream>
#include "sale/Sale.h"
#include "discount/ItemDiscount.h"
#include "discount/SumDiscount.h"

using namespace std;


int main() {
    Sale sale;
    SaleItem saleItem1(111, 100);
    SaleItem saleItem2(222, 100);
    SaleItem saleItem3(333, 100);
    SaleItem saleItem4(444, 100);
    sale.add(saleItem1);
    sale.add(saleItem2);
    sale.add(saleItem3);
    sale.add(saleItem4);

    Discount* newDiscount1;
    newDiscount1 = new ItemDiscount(111, 10);
    Discount* newDiscount2;
    newDiscount2 = new ItemDiscount(222, 10);
    Discount* newDiscount3;
    newDiscount3 = new ItemDiscount(333, 15);
    Discount* newDiscount4;
    newDiscount4 = new ItemDiscount(444, 20);


    SumDiscount sumDiscount;
    sumDiscount.add(newDiscount1);
    sumDiscount.add(newDiscount2);
    sumDiscount.add(newDiscount3);
    sumDiscount.add(newDiscount4);

    cout << sumDiscount.calc(sale) << "\n";

    delete newDiscount1;
    delete newDiscount2;
    delete newDiscount3;
    delete newDiscount4;

    return 0;
}
