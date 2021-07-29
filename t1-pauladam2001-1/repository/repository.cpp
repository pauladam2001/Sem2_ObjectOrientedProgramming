//
// Created by paula on 4/5/2021.
//

#include "repository.h"

Repository::Repository() = default;

void Repository::add_5_elements() {
    add_repo("E_Coli_K12", "yqgE", "ATGACATCATCATTG");
    add_repo("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG");
    add_repo("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG");
    add_repo("E_Coli_ETEC", "yqgE", "GTGACAGCGCCCTTCTTTCCACG");
    add_repo("E_Coli_K12", "hokC ", "TTAATGAAGCATAAGCTTGATTTC");
}

vector<Gene> Repository::getData() {
    return this->data;
}

int Repository::add_repo(string organism, string name, string sequence) {
    int inRepo = this->search_in_repository(organism, name);
    if (inRepo != -1)
        return 0;
    else {
        Gene newGene(organism, name, sequence);
        this->data.push_back(newGene);
        return 1;
    }
}

int Repository::search_in_repository(string organism, string name) {
    int index = 0;
    for (auto& element: this->data) {
        if (element.getOrganism() == organism && element.getName() == name)
            break;
        index++;
    }
    if (index == this->data.size())
        return -1;
    return index;
}

Repository::~Repository() = default;
