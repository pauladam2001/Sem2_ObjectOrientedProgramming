//
// Created by paula on 4/5/2021.
//

#ifndef T1_PAULADAM2001_1_SERVICE_H
#define T1_PAULADAM2001_1_SERVICE_H

#include "repository.h"
#include "gene.h"


class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    /// Add a gene (calls the repository function for add)
    /// \param organism - the organism
    /// \param name - the name of the gene
    /// \param sequence - the sequence of the gene
    /// \return - 1 if the gene was added, 0 otherwise
    int add_service(string organism, string name, string sequence);

    vector<Gene> sort_data();

    static int comparator_function(Gene g1, Gene g2);

    Repository& getReposository();

    vector<Gene> get_genes_sequence(string sequence);

    /// Calculates the longest common subsequence between 2 genes
    /// \param organism1 - organism 1 (field from gene)
    /// \param name1 - the name of the first gene
    /// \param organism2 - organism 2 (field from gene)
    /// \param name2 - the name of the second gene
    /// \return - the longest common subsequence of the 2 genes
    string longest_subseq_service(string organism1, string name1, string organism2, string name2);

    ~Service();
};

#endif //T1_PAULADAM2001_1_SERVICE_H
