//
// Created by paula on 5/20/2021.
//

#ifndef CARS_REPO_H
#define CARS_REPO_H

#include "bill.h"
#include <vector>

using namespace std;

class Repository {
private:
    vector<Bill> data;

    vector<Bill> load_data();

public:
    Repository();

    vector<Bill> getData();

    ~Repository();
};

#endif //CARS_REPO_H
