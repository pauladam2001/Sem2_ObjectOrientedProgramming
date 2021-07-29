//
// Created by Alexandra on 6/21/2021.
//

#pragma once
#include "UserRepo.h"
#include "AnswerRepo.h"
#include "QuestionRepo.h"
#include "Observer.h"

class Service: public Observable {

private:
    UserRepo& users;
    AnswerRepo& answers;
    QuestionRepo& questions;

public:
    Service(UserRepo& users, AnswerRepo& answers, QuestionRepo& questions);
    ~Service();

    vector<User>& getUsers();
    vector<Answer>& getAnswers();
    vector<Question>& getQuestions();

    void sortByNrAnswers();
    void addQuestion(string text, string name);
    int findID();
    int findIDAnswer();
    void addAnswer(string text, string name, string questionID);
//    static vector<string> tokenize(string str, char delimiter);
//    Answer getAnswerByID(string textToSplit);
    int findAnswer(string id);
    void updateNrVotes(Answer& a, int nrVotes);
    vector<Answer> getAnswersForQuestion(Question q);

};
