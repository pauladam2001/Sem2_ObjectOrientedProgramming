//
// Created by paula on 5/24/2021.
//

#ifndef T3_PAULADAM2001_SERVICE_H
#define T3_PAULADAM2001_SERVICE_H

#include "weather.h"
#include "repo.h"

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    vector<TimeInterval> getData();

    vector<TimeInterval> filter(int probability);

    vector<TimeInterval> filter_checkbox(string string1, string string2, string string3, string string4, string string5);

    vector<TimeInterval> filter_both(int probability, string string1, string string2, string string3, string string4, string string5);

    ~Service();
};

#endif //T3_PAULADAM2001_SERVICE_H
