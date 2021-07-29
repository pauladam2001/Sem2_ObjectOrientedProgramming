//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_STAR_H
#define STAR_CATALOGUE_STAR_H

#include <string>
#include <sstream>

using namespace std;


class Star {
private:
    string name;
    string constellation;
    int ra;
    int dec;
    int diameter;

public:
    Star();

    Star(string name, string constellation, int ra, int dec, int diameter);

    string getName();

    string getConstellation();

    int getRA();

    int getDec();

    int getDiameter();

    friend istream& operator>>(istream&, Star&);

    friend ostream& operator<<(ostream&, const Star&);

    ~Star();
};


#endif //STAR_CATALOGUE_STAR_H
