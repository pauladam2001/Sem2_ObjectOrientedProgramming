//
// Created by paula on 5/24/2021.
//

#ifndef T3_PAULADAM2001_REPO_H
#define T3_PAULADAM2001_REPO_H

#include "weather.h"
#include <vector>
using namespace std;

class Repository {
private:
    vector<TimeInterval> data;

    vector<TimeInterval> load_data();

public:
    Repository();

    vector<TimeInterval> getData();

    ~Repository();
};

#endif //T3_PAULADAM2001_REPO_H
