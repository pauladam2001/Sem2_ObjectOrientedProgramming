//
// Created by paul on 3/1/2021.
//

#ifndef A23_PAULADAM2001_USERINTERFACE_H
#define A23_PAULADAM2001_USERINTERFACE_H

#include "controller/service.h"
#include "validation//validators.h"


typedef struct {
    Service* medicineService;
} userInterface;


userInterface* init_userInterface();
/*
 * Creates a new userInterface
 * Input: None
 * Output: A pointer to an object of type userInterface
 */

void start_program(userInterface* interface);
/*
 * Starts the program
 * Input: - interface = a pointer to an object of type userInterface
 * Output: None
 */

void userInterface_destructor(userInterface* interface);
/*
 * Deallocates the memory used for a userInterface
 * Input: - interface = a pointer to an object of type userInterface
 * Output: None
 */


#endif //A23_PAULADAM2001_USERINTERFACE_H
