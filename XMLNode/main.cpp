#include <iostream>
#include "XMLAttribute.h"
#include "XMLNode.h"
#include <cassert>

using namespace std;

void fct2() {
    XMLAttribute a1{ "age", "40" };
    assert(a1.getXMLString() == "age=40");
    XMLAttribute a2{ "profession", "comedian" };
    XMLNode ch1 {"firstname", "Anna"};
    assert(ch1.getXMLString() == "<firstname>Anna</firstname>");
    XMLNode ch2{ "lastname", "Smith" };

    XMLNode p1{ "person", ""};
    p1.addAttribute(a1).addAttribute(a2);
    p1.addChildNode(ch1).addChildNode(ch2);

    XMLNode p2{"dog", "Happy"};

    XMLNode rootNode{ "root", ""};
    rootNode.addChildNode(p1).addChildNode(p2);

    cout << rootNode; //prints: <root><person age="40" profession="comedian"><firstname>Anna</firstname><lastname>Smith</lastname></person><dog>Happy</dog>
}

int main() {
    fct2();

    return 0;
}
