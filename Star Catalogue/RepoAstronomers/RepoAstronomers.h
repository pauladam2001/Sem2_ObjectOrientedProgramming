//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_REPOASTRONOMERS_H
#define STAR_CATALOGUE_REPOASTRONOMERS_H

#include <vector>
#include <string>
#include "../Astronomer/Astronomer.h"
#include <fstream>

using namespace std;


class RepoAstronomers {
private:
    vector<Astronomer> astronomers;

    void LoadData();

public:
    RepoAstronomers();

    vector<Astronomer>& getAll();

    ~RepoAstronomers();
};


#endif //STAR_CATALOGUE_REPOASTRONOMERS_H
