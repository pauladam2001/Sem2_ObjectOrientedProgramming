//
// Created by Alexandra on 6/20/2021.
//

#include "QuestionRepo.h"

QuestionRepo::QuestionRepo() {
    this->LoadData();
}

QuestionRepo::~QuestionRepo() {

}

vector<Question> &QuestionRepo::getQuestions() {
    return this->questions;
}

void QuestionRepo::LoadData() {
    ifstream inFile("questions.txt");
    Question currentElement;
    this->questions.clear();
    while(inFile >> currentElement) {
        this->questions.push_back(currentElement);
    }
    inFile.close();
}

void QuestionRepo::SaveData() {
    ofstream OutFile("questions.txt");
    for(auto & q: this->questions){
        OutFile<<q<<'\n';
    }
}

void QuestionRepo::addQuestion(Question q) {
    this->questions.push_back(q);
    this->SaveData();
}
