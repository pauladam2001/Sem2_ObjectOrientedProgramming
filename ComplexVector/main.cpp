#include <iostream>
#include <string>
#include <cstring>
#include "classes/Complex.h"
#include "classes/vector.h"
#include <cassert>
#include <vector>

using namespace std;


void complex() {
    Complex a{}, b{1, 2}, c{6, 4}, d{b};
    assert(a.getReal() == 0 && a.getImaginary() == 0);
    assert(c.getImaginary() == 4);
    assert(b == d);
    Complex res1 = c / 2;
    cout << res1 << "\n"; // prints: 3+2i
    try {
        Complex res2 = b / 0;
    }
    catch (runtime_error& e) {
        assert(strcmp(e.what(), "Division by zero!") == 0);
    }

    Vector<string> v1{std::vector<string>{"hello", "bye"}};
    v1.printAll(std::cout); // prints: hello, bye,

    Vector<Complex> v2{std::vector<Complex>{a, b, c, d}};
    v2.printAll(std::cout); // prints: 0+0i, 1+2i, 6+4i, 1+2i,
}

int main() {
    complex();

    return 0;
}
