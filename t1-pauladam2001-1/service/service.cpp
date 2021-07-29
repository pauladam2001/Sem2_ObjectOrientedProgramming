//
// Created by paula on 4/5/2021.
//

#include "service.h"
#include <algorithm>
#include <vector>

Service::Service(Repository &repository):repository{repository} {

}

int Service::add_service(string organism, string name, string sequence) {
    if (this->repository.add_repo(organism, name, sequence) == 0)
        return 0;
    return 1;
}

Repository &Service::getReposository() {
    return this->repository;
}

int Service::comparator_function(Gene g1, Gene g2) {
    return (g1.getSequence().length() > g2.getSequence().length());
}

vector<Gene> Service::sort_data() {
    vector<Gene> data = this->repository.getData();
    sort(data.begin(), data.end(), comparator_function);
    return data;
}

vector<Gene> Service::get_genes_sequence(string sequence) {
    vector<Gene> data = this->repository.getData();
    vector<Gene> newData;
    for (auto& element: data) {
        size_t found = element.getSequence().find(sequence);
        if (found != string::npos)
            newData.push_back(element);
    }
    return newData;
}

string Service::longest_subseq_service(string organism1, string name1, string organism2, string name2) {
    int inRepo1, inRepo2;
    inRepo1 = this->repository.search_in_repository(organism1, name1);
    inRepo2 = this->repository.search_in_repository(organism2, name2);
    string sequence1, sequence2;
    sequence1 = this->repository.getData()[inRepo1].getSequence();
    sequence2 = this->repository.getData()[inRepo2].getSequence();

//    string s1 = sequence1.pop_back();
//    string s2 = sequence2.pop_back();
    return sequence1;  //TODO not done
}

Service::~Service() = default;
