//
// Created by paula on 6/21/2021.
//

#ifndef QUIZ_PARTICIPANT_H
#define QUIZ_PARTICIPANT_H

#include <string>
#include <sstream>

using namespace std;


class Participant {
private:
    string name;
    int score;

public:
    Participant() = default;

    Participant(string name);

    string getName();

    int getScore();

    void setScore(int score);

    friend istream& operator>>(istream&, Participant&);

    ~Participant() = default;
};


#endif //QUIZ_PARTICIPANT_H
