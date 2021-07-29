#include <iostream>
#include "beverages.h"

using namespace std;


int main() {
    BeverageMachine beverageMachine;
    beverageMachine.prepare("Tea", 0);
    beverageMachine.prepare("Coffee", 1);
    beverageMachine.prepare("Coffee", 2);

    return 0;
}
