//
// Created by paula on 6/20/2021.
//

#include "Star.h"

Star::Star() = default;

Star::Star(string name, string constellation, int ra, int dec, int diameter):name{name}, constellation{constellation}, ra{ra},
                                                                             dec{dec}, diameter{diameter} {

}

string Star::getName() {
    return this->name;
}

string Star::getConstellation() {
    return this->constellation;
}

int Star::getRA() {
    return this->ra;
}

int Star::getDec() {
    return this->dec;
}

int Star::getDiameter() {
    return this->diameter;
}

istream &operator>>(istream &input, Star &s) {
    input>>s.name>>s.constellation>>s.ra>>s.dec>>s.diameter;
    return input;
}

ostream &operator<<(ostream &output, const Star &s) {
    output<<s.name<<" "<<s.constellation<<" "<<s.ra<<" "<<s.dec<<" "<<s.diameter;
    return output;
}

Star::~Star() = default;

