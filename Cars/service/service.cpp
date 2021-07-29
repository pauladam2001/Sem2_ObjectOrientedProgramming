//
// Created by paula on 5/20/2021.
//

#include "service.h"
#include <algorithm>

Service::Service(Repository& repository):repository{repository} {

}

vector<Car> Service::getData() {
    return this->repository.getData();
}

Service::~Service() {

}

bool sort_function(Car c1, Car c2) {
    return (c1.getName() < c2.getName());
}

vector<Car> Service::sort_by_name() {
    vector<Car> data = this->getData();

    sort(data.begin(), data.end(), sort_function);

    return data;
}

int Service::nr_of_cars(string name) {
    int counter = 0;
    for(auto &element : this->getData())
        if (element.getName() == name)
            counter++;
    return counter;
}
