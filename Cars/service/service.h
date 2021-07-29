//
// Created by paula on 5/20/2021.
//

#ifndef CARS_SERVICE_H
#define CARS_SERVICE_H

#include "car.h"
#include "repo.h"

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    vector<Car> getData();

    vector<Car> sort_by_name();

    int nr_of_cars(string name);

    ~Service();
};

#endif //CARS_SERVICE_H
