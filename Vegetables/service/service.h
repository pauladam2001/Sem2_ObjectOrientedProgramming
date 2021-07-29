//
// Created by paula on 5/20/2021.
//

#ifndef CARS_SERVICE_H
#define CARS_SERVICE_H

#include "vegetable.h"
#include "repo.h"

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    vector<Vegetable> getData();

    vector<Vegetable> sort_by_family();

    vector<string> get_unique_families();

    vector<Vegetable> get_family_vegetables(string family);

    ~Service();
};

#endif //CARS_SERVICE_H
