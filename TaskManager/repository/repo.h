//
// Created by paula on 5/20/2021.
//

#ifndef CARS_REPO_H
#define CARS_REPO_H

#include "task.h"
#include <vector>

using namespace std;

class Repository {
private:
    vector<Task> data;

    vector<Task> load_data();

public:
    Repository();

    vector<Task> getData();

    ~Repository();
};

#endif //CARS_REPO_H
