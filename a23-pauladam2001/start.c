//
// Created by paul on 3/2/2021.
//

//#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include "ui/userInterface.h"
#include "test/tests.h"


int main() {
//    run_tests();

    setbuf(stdout, NULL);

    userInterface* newInterface = init_userInterface();
    start_program(newInterface);
    userInterface_destructor(newInterface);

    _CrtDumpMemoryLeaks();
//    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
//    _CrtSetBreakAlloc(71);
//    _CrtSetBreakAlloc(70);
//    _crtBreakAlloc = 83;
//    if (_CrtDumpMemoryLeaks()) {
//        printf("\nLeaks found!\n");
//    }
//    else {
//        printf("\nNo leaks found!\n");
//    }
    return 0;
}
