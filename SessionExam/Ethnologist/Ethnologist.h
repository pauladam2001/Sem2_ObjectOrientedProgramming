//
// Created by paula on 6/22/2021.
//

#ifndef E2_PAULADAM2001_1_ETHNOLOGIST_H
#define E2_PAULADAM2001_1_ETHNOLOGIST_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Ethnologist {
private:
    string name;
    string area;

public:
    Ethnologist() = default;

    Ethnologist(string name, string area);

    string getName();

    string getArea();

    static vector<string> tokenize(string str, char delimiter);

    friend istream& operator>>(istream&, Ethnologist&);

    ~Ethnologist() = default;
};


#endif //E2_PAULADAM2001_1_ETHNOLOGIST_H
