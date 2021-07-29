//
// Created by Alexandra on 6/20/2021.
//

#pragma once
using namespace std;
#include <sstream>
#include <vector>
#include <string>



class Answer {

private:
    string id;
    string idQuestion;
    string name;
    string text;
    int nrVotes;

public:

    Answer();
    Answer(string id, string idQuestion, string name, string text, int nrVotes);
    ~Answer();

    string getID();
    string getQuestionID();
    string getName();
    string getText();
    int getNrVotes();

    void setNrVotes(int nrVotes);

    static vector<string> tokenize(string str, char delimiter);
    friend ostream& operator<<(ostream&, const Answer&);

    friend istream& operator>>(istream&, Answer&);

};
