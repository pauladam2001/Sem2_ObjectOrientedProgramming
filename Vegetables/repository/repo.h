//
// Created by paula on 5/20/2021.
//

#ifndef CARS_REPO_H
#define CARS_REPO_H

#include "vegetable.h"
#include <vector>

using namespace std;

class Repository {
private:
    vector<Vegetable> data;

    vector<Vegetable> load_data();

public:
    Repository();

    vector<Vegetable> getData();

    ~Repository();
};

#endif //CARS_REPO_H
