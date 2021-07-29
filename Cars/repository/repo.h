//
// Created by paula on 5/20/2021.
//

#ifndef CARS_REPO_H
#define CARS_REPO_H

#include "car.h"
#include <vector>

using namespace std;

class Repository {
private:
    vector<Car> data;

    vector<Car> load_data();

public:
    Repository();

    vector<Car> getData();

    ~Repository();
};

#endif //CARS_REPO_H
