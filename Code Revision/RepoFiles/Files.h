//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_FILES_H
#define CODE_REVISION_FILES_H

#include "../Observer/Observer.h"
#include "../SourceFile/SourceFile.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Files : public Observable {
private:
    vector<SourceFile> files;

    void load_data();

public:
    Files();

    void add_sourceFile(SourceFile f);

    void makeRevised(SourceFile& f, string name);

    vector<SourceFile>& getAll();

    ~Files() = default;
};


#endif //CODE_REVISION_FILES_H
