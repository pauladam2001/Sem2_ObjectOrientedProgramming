//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_STUDENT_H
#define BACHELOR_THESES_STUDENT_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Student {
private:
    string id;
    string name;
    string email;
    int year;
    string title;
    string coordinator;

public:
    Student() = default;

    Student(string id, string name, string email, int year, string title, string coordinator);

    string getId();

    string getName();

    string getEmail();

    int getYear();

    string getTitle();

    string getCoordinator();

    void setEmail(string email);

    void setTitle(string title);

    void setCoordinator(string coordinator);

    friend istream& operator>>(istream&, Student&);

    static vector<string> tokenize(const string& str, char delimiter);

    bool operator==(const Student& s);

    ~Student() = default;
};


#endif //BACHELOR_THESES_STUDENT_H
