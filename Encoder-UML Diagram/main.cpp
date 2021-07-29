#include <iostream>
#include "Communication.h"
#include "AlienEncoder.h"
#include "MorseEncoder.h"
#include "Mixer.h"

using namespace std;


int main() {
    Communication* c1 = new Communication(new MorseEncoder());
    c1->addMessage("daria");
    c1->addMessage("dammnnria");
    cout << c1->communicate();

    Communication* c2 = new Communication(new Mixer(new AlienEncoder("ET"), new MorseEncoder()));
    c2->addMessage("zmeura");
    c2->addMessage("afine");
    cout << c2->communicate();

    delete c1;
    delete c2;

    return 0;
}
