//
// Created by paula on 6/21/2021.
//

#ifndef QUIZ_REPOPARTICIPANTS_H
#define QUIZ_REPOPARTICIPANTS_H

#include "../Participant/Participant.h"
#include "../Question/Question.h"
#include "../Observer/Observer.h"
#include <fstream>
#include <vector>


class RepoParticipants {
private:
    vector<Participant> participants;

    void load_data();

public:
    RepoParticipants();

    vector<Participant>& getParticipants();

    void updateParticipantScore(Question q, string answer, Participant& p);

    ~RepoParticipants() = default;
};


#endif //QUIZ_REPOPARTICIPANTS_H
