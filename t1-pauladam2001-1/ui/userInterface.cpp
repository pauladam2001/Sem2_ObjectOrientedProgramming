//
// Created by paula on 4/5/2021.
//

#include "userInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

UserInterface::UserInterface(Service &service):service{service} {

}

void UserInterface::print_genes() {
    cout<<endl;
    vector<Gene> data = this->service.getReposository().getData();
    for (auto & element : data) {
//        char string[100];
//        element.to_string(string);
        cout<<element.to_string()<<endl;
    }
    cout<<endl;
}

void UserInterface::print_genes_decreasing() {
    cout<<endl;
    vector<Gene> data = this->service.sort_data();
    for (auto & element : data) {
//        char string[100];
//        element.to_string(string);
        cout<<element.to_string()<<endl;
    }
    cout<<endl;
}

void UserInterface::add_gene() {
    int sem = 1;
    string organism, name, sequence;
    cout<<endl<<"Organism:";
    cin>>organism;
    cout<<"Name:";
    cin>>name;
    cout<<"Sequence:";
    cin>>sequence;

    for (char index: sequence) {
        if (isdigit(index))
            sem = 0;
        if (isalpha(index) && (index != 'A' && index != 'C' && index != 'G' && index != 'T'))
            sem = 0;
    }

    if (sem == 0)
        cout<<endl<<"The sequence is invalid!"<<endl;
    else {
        if (this->service.add_service(organism, name, sequence) == 1)
            cout<<endl<<"Gene added successfully!"<<endl;
        else
            cout<<endl<<"Gene already in repository!"<<endl;
    }
}

void UserInterface::genes_including_sequence() {
    string sequence;
    cout<<endl<<"Introduce sequence:";
    cin>>sequence;
    vector<Gene> newData = this->service.get_genes_sequence(sequence);
    cout<<endl;
    for (auto & element : newData) {
        cout<<element.to_string()<<endl;
    }
    cout<<endl;
}

void UserInterface::longest_common_subseq() {
    string organism1, organism2, name1, name2;
    cout<<endl<<"Organism 1:";
    cin>>organism1;
    cout<<"Name 1:";
    cin>>name1;
    cout<<endl<<"Organism 2:";
    cin>>organism2;
    cout<<"Name 2:";
    cin>>name2;
    this->service.longest_subseq_service(organism1, name1, organism2, name2);
    cout<<"Not done!";
}

void UserInterface::print_menu() {
    cout<<"1. Add a new gene;"<<endl;
    cout<<"2. Print all genes;"<<endl;
    cout<<"3. Show all the genes, with all their information, sorted in decreasing order of sequence length;"<<endl;
    cout<<"4. Show the genes that include the sequence entered by user;"<<endl;
    cout<<"5. Given a pair of organism and gene names, display their longest common subsequence;"<<endl;
    cout<<"0. Exit the program."<<endl<<endl;
    cout<<"Your option:";
}

void UserInterface::start_program() {
    char option;
    do {
        print_menu();
        cin>>option;

        switch (option) {
            case '0': {
                cout<<endl<<"See you later!";
                exit(0);
            }
            case '1': {
                this->add_gene();
                break;
            }
            case '2': {
                this->print_genes();
                break;
            }
            case '3': {
                this->print_genes_decreasing();
                break;
            }
            case '4': {
                this->genes_including_sequence();
                break;
            }
            case '5': {
                this->longest_common_subseq();
                break;
            }
            default: {
                cout<<endl<<"This is not a command!"<<endl;
                break;
            }
        }
    } while (option != '0');
}

UserInterface::~UserInterface() = default;
