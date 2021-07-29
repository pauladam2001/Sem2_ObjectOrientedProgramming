#include <iostream>
#include "adder.h"

using namespace std;


void function2() {
    Adder<int> add{5}; // build a new Adder, with initial value 5
    add = add + 5 + 2; // add values 5 and 2
    ++add;	// adds the last added value (2) again
    add = add + 8; // add value 8
    cout << add.sum() << "\n"; // print sum, so far: 22 (5+5+2+2+8)
    --add; // eliminate last added value
    cout << add.sum() << "\n"; // print modified sum: 14
    --(--add); // eliminate the two previously added values
    cout << add.sum() << "\n"; // print modified sum: 10
    try {
        --(--(--add));
    }
    catch (runtime_error& ex) {
        cout << ex.what(); // prints "No more values!"
    }
}

int main() {
    function2();

    return 0;
}
