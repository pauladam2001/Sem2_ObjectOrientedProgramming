//
// Created by paula on 6/20/2021.
//

#include "Files.h"

Files::Files() {
    this->load_data();
}

void Files::load_data() {
    std::ifstream inFile("sources.txt");
    SourceFile currentFile;
    this->files.clear();
    while (inFile >> currentFile)
        this->files.push_back(currentFile);
    inFile.close();
}

void Files::add_sourceFile(SourceFile f) {
    this->files.push_back(f);
    this->notify();
}

void Files::makeRevised(SourceFile &f, string name) {
    for (auto& file : this->files)
        if (file == f) {
            file.setStatus("revised");
            file.setReviewer(name);
        }
    this->notify();
}

vector<SourceFile> &Files::getAll() {
    return this->files;
}
