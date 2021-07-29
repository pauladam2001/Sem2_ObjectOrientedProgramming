//
// Created by paula on 4/5/2021.
//

#ifndef T1_PAULADAM2001_1_REPOSITORY_H
#define T1_PAULADAM2001_1_REPOSITORY_H

#include "gene.h"
#include <vector>


class Repository {
private:
    vector<Gene> data{};

public:
    Repository();

    void add_5_elements();

    vector<Gene> getData();

    /// Add a new gene in the repository (only if it is not already in it)
    /// \param organism - the organism
    /// \param name - the name of the gene
    /// \param sequence - the sequence of the gene
    /// \return - 1 if gene was added, 0 otherwise
    int add_repo(string organism, string name, string sequence);

    int search_in_repository(string organism, string name);

    ~Repository();
};

#endif //T1_PAULADAM2001_1_REPOSITORY_H
