//
// Created by Alexandra on 6/20/2021.
//

#include "Question.h"

Question::Question() {

}

Question::Question(string id, string text, string name): id{id}, text{text}, name{name} {

}

Question::~Question() {

}

string Question::getID() {
    return this->id;
}

string Question::getText() {
    return this->text;
}

string Question::getName() {
    return this->name;
}

vector <string> Question::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

ostream &operator<<(ostream &output, const Question &q) {
    output<<q.id<<";"<<q.text<<";"<<q.name;
    return output;
}

istream &operator>>(istream &input, Question &q) {
    string line;
    getline(input, line);
    vector<string> tokens = Question::tokenize(line, ';');
    if(tokens.size() != 3)
        return input;
    q.id = tokens[0];
    q.text = tokens[1];
    q.name = tokens[2];
    return input;
}
