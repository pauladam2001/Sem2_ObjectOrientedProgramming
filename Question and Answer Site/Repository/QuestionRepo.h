//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include <fstream>
#include "Question.h"

class QuestionRepo {

private:
    vector<Question> questions;
    void LoadData();
    void SaveData();

public:
    QuestionRepo();
    ~QuestionRepo();
    vector<Question>& getQuestions();
    void addQuestion(Question q);

};