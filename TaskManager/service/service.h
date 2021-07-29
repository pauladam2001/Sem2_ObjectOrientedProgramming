//
// Created by paula on 5/20/2021.
//

#ifndef CARS_SERVICE_H
#define CARS_SERVICE_H

#include "task.h"
#include "repo.h"

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    vector<Task> getData();

    vector<Task> sort_by_priority();

    int compute_total_duration(int priority);

    ~Service();
};

#endif //CARS_SERVICE_H
