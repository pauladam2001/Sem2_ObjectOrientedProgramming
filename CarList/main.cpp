#include <iostream>
#include <cassert>
#include <cstring>
#include "classes/car.h"
#include "classes/list.h"

using namespace std;


void function1() {
    List<Car, int> list1;
    try {
        list1.sortByFirstComponent();
        assert(false);
    }
    catch (runtime_error& e) { assert(strcmp(e.what(), "List is empty!") == 0);	}

    list1.add(Car{ "Audi", 20 }, 8);
    list1.add(Car{ "Volkswagen", 10 }, 9);
    list1.add(Car{ "Bentley", 300 }, 10);

    list1.sortByFirstComponent();
    list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9
    list1.sortBySecondComponent();
    list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}

int main() {
    function1();

    return 0;
}
