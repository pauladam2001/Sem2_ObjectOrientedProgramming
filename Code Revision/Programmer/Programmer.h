//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_PROGRAMMER_H
#define CODE_REVISION_PROGRAMMER_H

#include <string>

using namespace std;


class Programmer {
private:
    string name;
    int nrRevisedFiles;
    int totalFiles;

public:
    Programmer() = default;

    Programmer(string name, int nrRevisedFiles, int totalFiles);

    string getName();

    int getNrRevisedFiles();

    int getTotalFiles();

    void setNrRevisedFiles(int number);

    friend istream& operator>>(istream&, Programmer&);

    ~Programmer() = default;
};


#endif //CODE_REVISION_PROGRAMMER_H
