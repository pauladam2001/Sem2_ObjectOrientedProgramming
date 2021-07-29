//
// Created by Alexandra on 6/20/2021.
//

#include "Answer.h"

Answer::Answer() {

}

Answer::Answer(string id, string idQuestion, string name, string text, int nrVotes): id{id}, idQuestion{idQuestion},
name{name}, text{text}, nrVotes{nrVotes}
{

}

Answer::~Answer() {

}

string Answer::getID() {
    return this->id;
}

string Answer::getQuestionID() {
    return this->idQuestion;
}

string Answer::getName() {
    return this->name;
}

string Answer::getText() {
    return this->text;
}

int Answer::getNrVotes() {
    return this->nrVotes;
}

vector <string> Answer::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

ostream &operator<<(ostream &output, const Answer &a) {
    output<<a.id<<";"<<a.idQuestion<<";"<<a.name<<";"<<a.text<<";"<<a.nrVotes;
    return output;
}

istream &operator>>(istream &input, Answer &a) {
    string line;
    getline(input, line);
    vector<string> tokens = Answer::tokenize(line, ';');
    if(tokens.size() != 5)
        return input;
    a.id = tokens[0];
    a.idQuestion = tokens[1];
    a.name = tokens[2];
    a.text = tokens[3];
    a.nrVotes = stoi(tokens[4]);
    return input;
}

void Answer::setNrVotes(int nrVotes) {
    this->nrVotes = nrVotes;
}
