//
// Created by paula on 4/5/2021.
//

#ifndef T1_PAULADAM2001_1_GENE_H
#define T1_PAULADAM2001_1_GENE_H

#include <string>
using namespace std;

class Gene {
private:
    string organism;
    string name;
    string sequence;

public:
    Gene();

    Gene(string organism, string name, string sequence);

    string getOrganism();

    string getName();

    string getSequence();

    string to_string();

    ~Gene();
};

#endif //T1_PAULADAM2001_1_GENE_H
