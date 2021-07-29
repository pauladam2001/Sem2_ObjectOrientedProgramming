//
// Created by paula on 6/21/2021.
//

#include "RepoQuestions.h"

RepoQuestion::RepoQuestion() {
    this->load_data();
}

void RepoQuestion::load_data() {
    std::ifstream inFile("questions.txt");
    Question currentQuestion;
    this->questions.clear();
    while (inFile >> currentQuestion)
        this->questions.push_back(currentQuestion);
    sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2) {return q1.getId() < q2.getId();});
    inFile.close();
}

void RepoQuestion::save_data() {
    ofstream OutFile("questions.txt");
    for(auto & q: this->questions){
        OutFile<<q<<'\n';
    }
}

vector<Question> &RepoQuestion::getQuestions() {
    return this->questions;
}

void RepoQuestion::addQuestion(Question q) {
    int pos = this->checkExistence(q);
    if(pos == -1){
        this->questions.push_back(q);
        ::sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2){
            return q1.getId()<q2.getId();
        });
        this->save_data();
        this->notify();
    }
    else
    {
        throw exception();
    }
}

int RepoQuestion::checkExistence(Question q) {
    for(int i = 0; i < this->questions.size(); i++){
        if(this->questions[i].getId() == q.getId())
            return i;
    }
    return -1;
}
