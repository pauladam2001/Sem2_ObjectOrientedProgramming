//
// Created by paula on 4/26/2021.
//

#ifndef T2_PAULADAM2001_1_UI_H
#define T2_PAULADAM2001_1_UI_H

#include "person.h"

using namespace std;

class UserInterface {
private:
    Person& person;

public:
    UserInterface(Person& person);

    void display();

    void print_menu();

    void save_file_ui();

    void add_ui();

    void start_program();

    ~UserInterface();
};


#endif //T2_PAULADAM2001_1_UI_H
