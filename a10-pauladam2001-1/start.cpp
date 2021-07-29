//
// Created by paul on 3/20/2021.
//

#include "repository/repository.h"
#include "repository/fileRepository.h"
#include "controller/service.h"
#include "controller/userService.h"
#include "ui/userInterface.h"
#include "ui/GUI.h"
#include "validation/validators.h"
#include <crtdbg.h>
#include <QApplication>
#include <QLabel>
#include "test/tests.h"


int main(int argc, char *argv[]) {

//    run_tests();

//    Repository repository;
//    repository.add_10_elements();


//    QApplication a{ argc, argv };
//    QLabel label{ "Hello world!" };
//    label.show();
//    return a.exec();

    QApplication a(argc, argv);

    FileRepository fileRepository(R"(C:\Users\paula\OneDrive\Documents\GitHub\a10-pauladam2001-1\data.txt)");

    Service service{fileRepository};
    UserService userService{fileRepository};
    Validator validator;

//    UserInterface userInterface(service, validator, userService);
//
//    userInterface.start_program();

    GUI gui(service, validator, userService);
    gui.show();

    return a.exec();

    _CrtDumpMemoryLeaks();

//    return 0;
}

