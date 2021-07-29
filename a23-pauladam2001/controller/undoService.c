//
// Created by paul on 3/8/2021.
//

#include "undoService.h"
#include <stdlib.h>

#define HISTORY_CAPACITY 10
#define CAPACITY 100


UndoService* init_undo_service() {
    UndoService* newUndoService = (UndoService*)malloc(sizeof(UndoService));

    if (newUndoService == NULL) {
        return NULL;
    }

    newUndoService->currentAction = 0;
    newUndoService->totalNrOfPerformedOperations = 0;
    newUndoService->maxPosition = 0;
    newUndoService->historyCapacity = HISTORY_CAPACITY;
    newUndoService->dataHistory = (DynamicArray**)malloc(HISTORY_CAPACITY * sizeof(DynamicArray*));

//    for (int index = 0; index < newUndoService->historyCapacity; index++) {
//        newUndoService->dataHistory[index] = (DynamicArray*)malloc(sizeof(DynamicArray));
//        newUndoService->dataHistory[index]->array = (Medicine*)malloc(CAPACITY * sizeof(Medicine));
//    }

    newUndoService->dataHistory[newUndoService->currentAction] = (DynamicArray*)malloc(sizeof(DynamicArray));
    newUndoService->dataHistory[newUndoService->currentAction]->array = (Medicine*)malloc(CAPACITY * sizeof(Medicine));

    if (newUndoService->dataHistory == NULL) {
        return NULL;
    }

    Repository* undoRepository = init_repository(CAPACITY);
    DynamicArray undoDynamicArray = get_data(undoRepository);

    newUndoService->dataHistory[newUndoService->currentAction]->capacity = undoDynamicArray.capacity;
    newUndoService->dataHistory[newUndoService->currentAction]->count = undoDynamicArray.count;
    for (int index = 0; index < undoDynamicArray.count; index ++) {
        newUndoService->dataHistory[newUndoService->currentAction]->array[index] = undoDynamicArray.array[index];
    }

    repository_destructor(undoRepository);
    dynamic_array_destructor(&undoDynamicArray);

    return newUndoService;
}

void save_data(UndoService* medicineUndoService, Repository* medicineRepository) {
    medicineUndoService->currentAction++;
    medicineUndoService->maxPosition++;

    if (medicineUndoService->currentAction == medicineUndoService->historyCapacity) {
        resize_undo_service(medicineUndoService);
    }

    medicineUndoService->totalNrOfPerformedOperations = medicineUndoService->currentAction;

    medicineUndoService->dataHistory[medicineUndoService->currentAction] = (DynamicArray*)malloc(sizeof(DynamicArray));
    medicineUndoService->dataHistory[medicineUndoService->currentAction]->array = (Medicine*)malloc(CAPACITY * sizeof(Medicine));

    DynamicArray undoDynamicArray = get_data(medicineRepository);
//    DynamicArray undoDynamicArray;
//    get_data_2(medicineRepository, &undoDynamicArray);

    medicineUndoService->dataHistory[medicineUndoService->currentAction]->capacity = undoDynamicArray.capacity;
    medicineUndoService->dataHistory[medicineUndoService->currentAction]->count = undoDynamicArray.count;

    for (int index = 0; index < undoDynamicArray.count; index ++) {
        medicineUndoService->dataHistory[medicineUndoService->currentAction]->array[index] = undoDynamicArray.array[index];
    }

    dynamic_array_destructor(&undoDynamicArray);
}

int undo_operation(UndoService* medicineUndoService) {
    if (medicineUndoService->currentAction == 0) {
        return 0;
    }
    medicineUndoService->currentAction--;
    return 1;
}

int redo_operation(UndoService* medicineUndoService) {
    if (medicineUndoService->currentAction == medicineUndoService->totalNrOfPerformedOperations) {
        return 0;
    }
    medicineUndoService->currentAction++;
    return 1;
}

DynamicArray* get_current_array(UndoService* medicineUndoService) {
    return medicineUndoService->dataHistory[medicineUndoService->currentAction];
}

void resize_undo_service(UndoService* medicineUndoService) {
    DynamicArray** resizeUndo = (DynamicArray**)malloc(medicineUndoService->historyCapacity * 2 * sizeof(DynamicArray*));
    for (int index = 0 ; index < medicineUndoService->historyCapacity; index ++) {
        resizeUndo[index] = medicineUndoService->dataHistory[index];
    }
//    for (int index = 0; index < medicineUndoService->totalNrOfPerformedOperations; index ++) {
//        free(medicineUndoService->dataHistory[index]->array);
//    }
    free(medicineUndoService->dataHistory);
    medicineUndoService->historyCapacity *= 2;
    medicineUndoService->dataHistory = resizeUndo;
}

void undo_service_destructor(UndoService* medicineUndoService) {
    for (int index = 0; index < medicineUndoService->maxPosition + 1; index++) {
        free(medicineUndoService->dataHistory[index]->array);
    }
    for (int index = 0; index < medicineUndoService->maxPosition + 1; index++) {
        free(medicineUndoService->dataHistory[index]);
    }
    free(medicineUndoService->dataHistory);
    free(medicineUndoService);
}
