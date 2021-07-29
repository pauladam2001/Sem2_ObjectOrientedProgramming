//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_REPOSTARS_H
#define STAR_CATALOGUE_REPOSTARS_H

#include <vector>
#include <string>
#include "../Star/Star.h"
#include <fstream>
#include "../Observer/Observer.h"

using namespace std;


class RepoStars: public Observable{
private:
    vector<Star> stars;

    void LoadData();

    void saveToFile();

public:
    RepoStars();

    vector<Star> filterStarsByConstellation(string constellation);

    vector<Star> filterStarsByName(string name);

    void addStar(const Star& s);

    vector<Star>& getAll();

    ~RepoStars();
};


#endif //STAR_CATALOGUE_REPOSTARS_H
