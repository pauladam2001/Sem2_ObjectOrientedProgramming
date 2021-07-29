//
// Created by paula on 5/20/2021.
//

#include "service.h"
#include <algorithm>

Service::Service(Repository& repository):repository{repository} {

}

vector<Task> Service::getData() {
    return this->repository.getData();
}

Service::~Service() {

}

bool sort_function(Task c1, Task c2) {
    return (c1.getPriority() < c2.getPriority());
}

vector<Task> Service::sort_by_priority() {
    vector<Task> data = this->getData();

    sort(data.begin(), data.end(), sort_function);

    return data;
}

int Service::compute_total_duration(int priority) {
    int totalDur = 0;
    for(auto &element : this->getData())
        if (element.getPriority() == priority)
            totalDur += element.getDuration();
    return totalDur;
}
