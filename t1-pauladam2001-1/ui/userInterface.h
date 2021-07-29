//
// Created by paula on 4/5/2021.
//

#ifndef T1_PAULADAM2001_1_USERINTERFACE_H
#define T1_PAULADAM2001_1_USERINTERFACE_H

#include "service.h"


class UserInterface {
private:
    Service& service;

    void print_menu();

    void add_gene();

    void print_genes();

    void print_genes_decreasing();

    void genes_including_sequence();

    void longest_common_subseq();

public:
    UserInterface(Service& service);

    void start_program();

    ~UserInterface();
};

#endif //T1_PAULADAM2001_1_USERINTERFACE_H
