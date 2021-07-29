//
// Created by paul on 3/20/2021.
//

#include "repository/repository.h"
#include "repository/fileRepository.h"
#include "controller/service.h"
#include "controller/userService.h"
#include "ui/userInterface.h"
#include "validation/validators.h"
#include <crtdbg.h>
//#include "test/tests.h"


int main() {

//    run_tests();

//    Repository repository;
//    repository.add_10_elements();

    FileRepository fileRepository(R"(C:\Users\paula\OneDrive\Documents\GitHub\a67-pauladam2001\data.txt)");

    Service service{fileRepository};
    UserService userService{fileRepository};
    Validator validator;
    UserInterface userInterface(service, validator, userService);

    userInterface.start_program();

    _CrtDumpMemoryLeaks();

    return 0;
}

