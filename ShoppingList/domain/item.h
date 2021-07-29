//
// Created by paula on 5/21/2021.
//

#ifndef SHOPPING_LIST_ITEM_H
#define SHOPPING_LIST_ITEM_H

#include <string>
#include <vector>

using namespace std;

class Item {
private:
    string category;
    string name;
    int quantity;

public:
    Item();

    Item(string category, string name, int quantity);

    string getCategory();

    string getName();

    int getQuantity();

    friend std::istream& operator>>(std::istream&, Item&);

    ~Item();
};

#endif //SHOPPING_LIST_ITEM_H
