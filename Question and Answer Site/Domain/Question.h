//
// Created by Alexandra on 6/20/2021.
//

#pragma once
using namespace std;
#include <sstream>
#include <vector>
#include <string>

class Question {

private:
    string id;
    string text;
    string name;

public:
    Question();
    Question(string id, string text, string name);
    ~Question();

    string getID();
    string getText();
    string getName();

    static vector<string> tokenize(string str, char delimiter);
    friend ostream& operator<<(ostream&, const Question&);

    friend istream& operator>>(istream&, Question&);
};
