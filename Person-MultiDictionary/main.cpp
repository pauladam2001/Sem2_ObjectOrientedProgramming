#include <iostream>
#include <cstring>
#include <cassert>
#include "MultiDictionary.h"
#include "Person.h"

using namespace std;


void function2() {
    MultiDictionary<int, string> d1{};
    d1.add(1, "a").add(2, "b").add(1, "c").add(3, "d");
    d1.print(std::cout); // prints 1 a; 2 b; 1 c; 3 d
    try {
        d1.erase(4, "w");
        assert(false);
    }
    catch (std::runtime_error& e) {
        try {
            assert(strcmp(e.what(), "Key does not exist!") == 0);
            d1.erase(2, "w");
            assert(false);   }
        catch (std::runtime_error& e) {
            assert(strcmp(e.what(), "Given value does not exist for given key!") == 0);
        }
    }

    d1.erase(1, "a");
    d1.print(std::cout); // prints 2 b; 1 c; 3 d
    MultiDictionary<string, Person> d2{};
    Person p1{ "Bianca", 20 }; Person p2{ "Andrei", 21 };
    d2.add("a", p1).add("a", p2);
    d2.print(std::cout); // prints a Bianca is 20 years old; a Andrei is 21 years old;.
    assert(d2.sizeForKey("a") == 2);
    assert(d2.sizeForKey("b") == 0);
}

int main() {
    function2();

    return 0;
}
