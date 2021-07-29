//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_REPOPROGRAMMERS_H
#define CODE_REVISION_REPOPROGRAMMERS_H

#include <string>
#include <vector>
#include <fstream>
#include "../Programmer/Programmer.h"
#include "../Observer/Observer.h"

using namespace std;


class RepoProgrammers : public Observable {
private:
    vector<Programmer> programmers;

    void load_data();

public:
    RepoProgrammers();

    vector<Programmer>& getAll();

    ~RepoProgrammers() = default;
};


#endif //CODE_REVISION_REPOPROGRAMMERS_H
