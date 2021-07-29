#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
#include "Person.h"
#include "SortedDictionary.h"

using namespace std;


void function1()
{
    SortedDictionary<int, string> d1{};
    d1.put(10, "j").put(2, "b").put(14, "m").put(1, "a");
    d1.print(std::cout); // prints 1 a; 2 b; 10 j; 14 m

    try {
        d1.put(2, "r");
        assert(false);
    }
    catch (std::runtime_error& e) {
        assert(strcmp(e.what(), "Element already exists!") == 0); }

    SortedDictionary<string, Person> d2{};
    Person p1{ "Bianca", 20 }; Person p2{ "Andrei", 21 };
    d2.put("b", p1).put("a", p2);
    d2.print(std::cout); // prints: a Andrei is 21 years old. b Bianca is 20 years old.

    Person p = d2.eraseFirst();
    assert(p == p2);
    assert(d2.size() == 1);
}

int main() {
    function1();

    return 0;
}
