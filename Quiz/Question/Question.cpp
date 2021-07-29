//
// Created by paula on 6/21/2021.
//

#include "Question.h"

Question::Question(int id, string text, string correctAnswer, int score): id{id}, text{text}, correctAnswer{correctAnswer}, score{score} {

}

int Question::getId() {
    return this->id;
}

string Question::getText() {
    return this->text;
}

string Question::getCorrectAnswer() {
    return this->correctAnswer;
}

vector<string> Question::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

ostream &operator<<(ostream &output, const Question &q) {
    output<<q.id<<";"<<q.text<<";"<<q.correctAnswer<<";"<<q.score;
    return output;
}

istream &operator>>(istream &input, Question &q) {
    string line;
    getline(input, line);
    vector<string> tokens = Question::tokenize(line, ';');
    if(tokens.size() != 4)
        return input;
    q.id = stoi(tokens[0]);
    q.text = tokens[1];
    q.correctAnswer = tokens[2];
    q.score = stoi(tokens[3]);
    return input;
}

int Question::getScore() {
    return this->score;
}
