//
// Created by Alexandra on 6/21/2021.
//

#include "Service.h"
#include <time.h>

Service::Service(UserRepo &users, AnswerRepo &answers, QuestionRepo &questions): users{users}, answers{answers}, questions{questions} {
    sortByNrAnswers();
}

Service::~Service() {

}

vector<User> &Service::getUsers() {
    return this->users.getUsers();
}

vector<Answer> &Service::getAnswers() {
    return this->answers.getAnswers();
}

vector<Question> &Service::getQuestions() {
    return this->questions.getQuestions();
}

void Service::sortByNrAnswers() {

    vector<int> nrAnswers(this->getQuestions().size());
    for(int i = 0; i < this->getQuestions().size(); i++){
        for(int j = 0; j < this->getAnswers().size(); j++){
            if(this->getAnswers()[j].getQuestionID() == this->getQuestions()[i].getID()){
                nrAnswers[i]++;
            }
        }
    }

    for(int i = 0; i < this->getQuestions().size()-1; i++){
        for(int j = i + 1; j < this->getQuestions().size(); j++){
            if(nrAnswers[i] < nrAnswers[j]){
                swap(nrAnswers[i], nrAnswers[j]);
                swap(this->getQuestions()[i], this->getQuestions()[j]);
            }
        }
    }

}

void Service::addQuestion(string text, string name) {
    int id = this->findID();
    Question q(to_string(id), text, name);
    this->questions.addQuestion(q);
    this->notify();
}

int Service::findID() {
    bool done = false;
    int id;
    while(!done){
        for(auto & q: this->getQuestions()) {
            srand(time(NULL));
            id = rand() % 1000;
            if(to_string(id) != q.getID()){
                done = true;
                break;
            }
        }
    }
    return id;
}

int Service::findIDAnswer() {
    bool done = false;
    int id;
    while(!done){
        for(auto & a: this->getAnswers()) {
            srand(time(NULL));
            id = rand() % 1000;
            if(to_string(id) != a.getID()){
                done = true;
                break;
            }
        }
    }
    return id;
}

void Service::addAnswer(string text, string name, string questionID) {
    int id = this->findIDAnswer();
    Answer a(to_string(id), questionID, name, text, 0);
    this->answers.addAnswer(a);
    this->notify();
}

vector<Answer> Service::getAnswersForQuestion(Question q) {
    vector<Answer> answers;
    for(auto & a: this->getAnswers()){
        if(q.getID() == a.getQuestionID()){
            answers.push_back(a);
        }
    }
    return answers;
}

//vector<string> Service::tokenize(string str, char delimiter) {
//    vector<string> result;
//    stringstream ss(str);
//    string token;
//    while (getline(ss, token, delimiter))
//        result.push_back(token);
//
//    return result;
//}
//
//
//Answer Service::getAnswerByID(string textToSplit) {
//    vector<string> tokens;
//    tokens = tokenize(textToSplit, '|');
//    string answerID = tokens[0];
//    int pos = findAnswer(answerID);
//    return this->getAnswers()[pos];
//}

int Service::findAnswer(string id) {
    for(int i = 0; i < this->getAnswers().size(); i++){
        if(this->getAnswers()[i].getID() == id)
            return i;
    }
    return -1;
}

void Service::updateNrVotes(Answer& a, int nrVotes) {
    int pos = findAnswer(a.getID());
    this->answers.setNrVotes(nrVotes, pos);
    this->notify();

}
