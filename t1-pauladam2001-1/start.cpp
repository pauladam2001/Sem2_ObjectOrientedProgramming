//
// Created by paula on 4/5/2021.
//

#include "repository/repository.h"
#include "service/service.h"
#include "ui/userInterface.h"


int main() {
    Repository repository;
    repository.add_5_elements();
    Service service{repository};
    UserInterface userInterface(service);

    userInterface.start_program();
}
