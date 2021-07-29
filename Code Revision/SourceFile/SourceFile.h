//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_SOURCEFILE_H
#define CODE_REVISION_SOURCEFILE_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class SourceFile {
private:
    string name;
    string status;
    string creator;
    string reviewer;

public:
    SourceFile() = default;

    SourceFile(string name, string creator);

    SourceFile(string name, string status, string creator, string reviewer);

    string getName();

    string getStatus();

    string getCreator();

    string getReviewer();

    void setReviewer(string reviewer);

    void setStatus(string status);

    friend istream& operator>>(istream&, SourceFile&);

    bool operator==(const SourceFile &s);
};


#endif //CODE_REVISION_SOURCEFILE_H
