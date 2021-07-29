//
// Created by paul on 3/20/2021.
//

#include "entity/trenchCoat.h"
#include "dynamicArray/dynamicArray.h"
#include "repository/repository.h"
#include "controller/service.h"
#include "controller/userService.h"
#include "ui/userInterface.h"
#include "validation/validators.h"
#include <crtdbg.h>
#include <iostream>
#include "test/tests.h"


int main() {                    //TODO sau in loc de transmitere prin pointeri puteam prin referinta

//    run_tests();

    dynamicArray<trenchCoat>* dynArray = new dynamicArray<trenchCoat>(100);
    Repository* repository = new Repository(dynArray);
    repository->add_10_elements();
    Service* service = new Service(repository);
    UserService* userService = new UserService(repository);
    Validator* validator = new Validator();
    UserInterface* userInterface = new UserInterface(service, validator, userService);

    userInterface->start_program();

    delete userInterface;


//    dynamicArray<int>* integers = new dynamicArray<int>(100);
//    for (int index = 0; index < 10; index++)
//        integers->add(index);
//    cout<<endl<<endl;
//    for (int index = 0; index < 10; index++)
//        cout<<integers->getData()[index];
//    delete integers;

    _CrtDumpMemoryLeaks();

    return 0;
}

