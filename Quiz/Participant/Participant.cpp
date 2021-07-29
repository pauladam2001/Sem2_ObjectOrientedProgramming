//
// Created by paula on 6/21/2021.
//

#include "Participant.h"

Participant::Participant(string name): name{name} {
    this->score = 0;
}

string Participant::getName() {
    return this->name;
}

int Participant::getScore() {
    return this->score;
}

void Participant::setScore(int score) {
    this->score = score;
}

istream &operator>>(istream &input, Participant &p) {
    input>>p.name>>p.score;
    return input;
}
