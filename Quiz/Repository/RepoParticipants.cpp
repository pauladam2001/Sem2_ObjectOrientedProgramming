//
// Created by paula on 6/21/2021.
//

#include "RepoParticipants.h"

RepoParticipants::RepoParticipants() {
    this->load_data();
}

void RepoParticipants::load_data() {
    ifstream inFile("participants.txt");
    Participant currentElement;
    this->participants.clear();
    while(inFile >> currentElement) {
        this->participants.push_back(currentElement);
    }
    inFile.close();
}

vector<Participant> &RepoParticipants::getParticipants() {
    return this->participants;
}

void RepoParticipants::updateParticipantScore(Question q, string answer, Participant &p) {
    if(q.getCorrectAnswer() == answer) {
        int newScore = p.getScore() + q.getScore();
        p.setScore(newScore);
    }
    else
        throw exception();
}
