#include <iostream>
#include "Order.h"
#include "Icecream.h"
#include "SimpleIceCream.h"
#include "IcecreamWithTopping.h"

int main() {
    Order order{};

    Icecream* icecream1;
    Icecream* icecream2;

    icecream1 = new SimpleIcecream("vanilla", 5);
    order.addIcecream(icecream1);

    icecream2 = new IcecreamWithChocolateTopping("pistachio", 7);
    order.addIcecream(icecream2);

    order.printOrder();

    delete icecream1;
    delete icecream2;

    return 0;
}
