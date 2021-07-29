//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_ASTRONOMER_H
#define STAR_CATALOGUE_ASTRONOMER_H

#include <string>
#include <sstream>

using namespace std;


class Astronomer {
private:
    string name;
    string constellation;

public:
    Astronomer();

    Astronomer(string name, string constellation);

    string getName();

    string getConstellation();

    friend istream& operator>>(istream&, Astronomer&);

    ~Astronomer();
};


#endif //STAR_CATALOGUE_ASTRONOMER_H
