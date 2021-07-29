//
// Created by paula on 6/21/2021.
//

#ifndef QUIZ_QUESTION_H
#define QUIZ_QUESTION_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Question {
private:
    int id;
    string text;
    string correctAnswer;
    int score;

public:
    Question() = default;

    Question(int id, string text, string correctAnswer, int score);

    int getId();

    string getText();

    string getCorrectAnswer();

    int getScore();

    static vector<string> tokenize(string str, char delimiter);

    friend ostream& operator<<(ostream&, const Question&);

    friend istream& operator>>(istream&, Question&);

    ~Question() = default;
};


#endif //QUIZ_QUESTION_H
