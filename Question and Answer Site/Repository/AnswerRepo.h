//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include <fstream>
#include "Answer.h"

class AnswerRepo {

private:
    vector<Answer> answers;
    void LoadData();
    void SaveData();

public:
    AnswerRepo();
    ~AnswerRepo();
    vector<Answer>& getAnswers();
    void addAnswer(Answer a);
    void setNrVotes(int nrVotes, int pos);

};
