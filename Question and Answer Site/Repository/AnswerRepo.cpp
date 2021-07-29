//
// Created by Alexandra on 6/20/2021.
//

#include "AnswerRepo.h"

AnswerRepo::AnswerRepo() {
    this->LoadData();
}

AnswerRepo::~AnswerRepo() {

}

vector<Answer> &AnswerRepo::getAnswers() {
    return this->answers;
}

void AnswerRepo::LoadData() {
    ifstream inFile("answers.txt");
    Answer currentElement;
    this->answers.clear();
    while(inFile >> currentElement) {
        this->answers.push_back(currentElement);
    }
    inFile.close();
}

void AnswerRepo::SaveData() {
    ofstream OutFile("answers.txt");
    for(auto & a: this->answers){
        OutFile<<a<<'\n';
    }

}

void AnswerRepo::addAnswer(Answer a) {
    this->answers.push_back(a);
    this->SaveData();
}

void AnswerRepo::setNrVotes(int nrVotes, int pos) {
    this->answers[pos].setNrVotes(nrVotes);
    this->SaveData();
}
