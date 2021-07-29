//
// Created by paul on 3/8/2021.
//

#ifndef A23_PAULADAM2001_UNDOSERVICE_H
#define A23_PAULADAM2001_UNDOSERVICE_H

#include "repository/repository.h"
//#include "dynamic_array/dynamicArray.h"

typedef struct {
    DynamicArray** dataHistory;
    int historyCapacity;
    int currentAction;  // where we are in the repository history
    int totalNrOfPerformedOperations;   // used to know when there are no more redos
    int maxPosition;  // needed for the destructor (otherwise we will not destroy everything)
} UndoService;

UndoService* init_undo_service();
/*
 * Creates a new UndoService
 * Input: None
 * Output: A pointer to an object of type UndoService
 */

void save_data(UndoService* medicineUndoService, Repository* medicineRepository);
/*
 * Saves a new repository to the 'list' of repositories
 * Input: - medicineUndoService = a pointer to an object of type UndoService
 *        - medicineRepository = a pointer to an object of type Repository
 * Output: None
 */

int undo_operation(UndoService* medicineUndoService);
/*
 * Undoes the last performed operation
 * Input: - medicineUndoService = a pointer to an object of type UndoService
 * Output: - 1, if the undo was successful
 *         - 0, if there are no more operations to undo
 */

int redo_operation(UndoService* medicineUndoService);
/*
 * Redoes the last operation that was undone
 * Input: - medicineUndoService = a pointer to an object of type UndoService
 * Output: - 1, if the redo was successful
 *         - 0, if there are no more operations to redo
 */

DynamicArray* get_current_array(UndoService* medicineUndoService);
/*
 * Returns a pointer to the current 'repository' in the undo service
 * Input: - medicineUndoService = a pointer to an object of type UndoService
 * Output: A pointer (to an object of type DynamicArray) to the current 'repository' in the undo service
 */

void resize_undo_service(UndoService* medicineUndoService);
/*
 * Multiplies the capacity of the 'undo' array by 2 when it becomes full
 * Input: - medicineUndoService = a pointer to an object of type UndoService
 * Output: None
 */

void undo_service_destructor(UndoService* medicineUndoService);
/*
 * Deallocates the memory used for a UndoService
 * Input: - medicineUndoService = a pointer to an object of type UndoService
 * Output: None
 */


#endif //A23_PAULADAM2001_UNDOSERVICE_H
