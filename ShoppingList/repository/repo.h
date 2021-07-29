//
// Created by paula on 5/21/2021.
//

#ifndef SHOPPING_LIST_REPO_H
#define SHOPPING_LIST_REPO_H

#include "item.h"
#include <vector>

using namespace std;

class Repository {
private:
    vector<Item> data;

    vector<Item> load_data();

public:
    Repository();

    vector<Item> getData();

    void delete_item(string category, string name);

    int search_in_repo(string category, string name);

    ~Repository();
};

#endif //SHOPPING_LIST_REPO_H
