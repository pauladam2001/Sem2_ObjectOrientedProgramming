//
// Created by paula on 5/21/2021.
//

#ifndef SHOPPING_LIST_SERVICE_H
#define SHOPPING_LIST_SERVICE_H

#include "item.h"
#include "repo.h"

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    vector<Item> getData();

    void delete_item_service(string category, string name);

    vector<Item> filter_by_category(string category);

    ~Service();
};

#endif //SHOPPING_LIST_SERVICE_H
