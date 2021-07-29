//
// Created by paula on 6/21/2021.
//

#ifndef QUIZ_REPOQUESTIONS_H
#define QUIZ_REPOQUESTIONS_H

#include "../Question/Question.h"
#include "../Observer/Observer.h"
#include <fstream>
#include <vector>


class RepoQuestion : public Observable {
private:
    vector<Question> questions;

    void load_data();

    void save_data();

public:
    RepoQuestion();

    vector<Question>& getQuestions();

    void addQuestion(Question q);

    int checkExistence(Question q);

    ~RepoQuestion() = default;
};


#endif //QUIZ_REPOQUESTIONS_H
