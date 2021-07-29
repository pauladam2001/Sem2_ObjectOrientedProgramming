//
// Created by paula on 4/26/2021.
//

#include "person.h"
#include "ui.h"

int main() {
    Person person("Paul");
    person.init_person();

    UserInterface userInterface(person);

    userInterface.start_program();

    return 0;
}

