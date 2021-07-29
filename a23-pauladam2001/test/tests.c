//
// Created by paul on 3/8/2021.
//

#include "tests.h"
#include <assert.h>
#include <string.h>
#include "entity/medicine.h"
#include "validation/validators.h"
#include "controller/service.h"
#include "controller/undoService.h"
#include "repository/repository.h"

void test_entity() {
    Medicine newMedicine;
    newMedicine = init_medicine("coldrex", 30, 15, 24);
    assert(strcmp(newMedicine.name, "coldrex") == 0);
    assert(newMedicine.concentration == 30);
    assert(newMedicine.quantity == 15);
    assert(newMedicine.price == 24);
    assert(strcmp(getName(&newMedicine), "coldrex") == 0);
    assert(getConcentration(&newMedicine) == 30);
    assert(getQuantity(&newMedicine) == 15);
    assert(getPrice(&newMedicine) == 24);
    //char string[50];
    //to_string(newMedicine, string);
    //printf("%s", string);
}

void test_validators() {
    assert(validate_string("Ana") == 1);
    assert(validate_string("A2na") == 0);
    assert(validate_int("234") == 1);
    assert(validate_int("23a4") == 0);
}

void test_repository() {
    Repository* newRepository;
    newRepository = init_repository(10);
    assert(newRepository != NULL);
    assert(newRepository->data.array != NULL);
    assert(newRepository->data.capacity == 10);
    assert(newRepository->data.count = 10);
    Medicine newMedicine;
    newMedicine = init_medicine("coldrex", 30, 15, 24);
    int result = add_medicine(newRepository, newMedicine);
    assert(result == 1);
    assert(newRepository->data.capacity == 20);  //means that the resize function is working correctly
    assert(newRepository->data.count == 11);
    result = add_medicine(newRepository, newMedicine);
    assert(newRepository->data.count == 11);    // just sets the quantity because the medicine already exists in the array
    result = delete_medicine(newRepository, "coldrex", 30);
    assert(result == 1);
    assert(newRepository->data.count == 10);
    result = delete_medicine(newRepository, "coldrex", 30);
    assert(result == 0);
    result = add_medicine(newRepository, newMedicine);
    assert(result == 1);
    result = update_price(newRepository, "coldrex", 30, 100);
    assert(result == 1);
    assert(getPrice(&newRepository->data.array[10]) == 100);
    result = update_price(newRepository, "paul", 30, 50);
    assert(result == 0);
    result = update_quantity(newRepository, "coldrex", 30, 200);
    assert(result == 1);
    assert(getQuantity(&newRepository->data.array[10]) == 200);
    result = update_quantity(newRepository, "paul", 32, 29);
    assert(result == 0);
    resize(newRepository);
    assert(newRepository->data.capacity == 40);
    result = search_in_repository(newRepository, "coldrex", 30);
    assert(result == 10);
    result = search_in_repository(newRepository, "paul", 12);
    assert(result == -1);
    repository_destructor(newRepository);
}

void test_service() {
    Service* newService;
    newService = init_service();
    char* result = add_medicine_service(newService, "piracetam", 60, 10, 50);
    assert(result == NULL);
    result = delete_medicine_service(newService, "piracetam", 60);
    assert(result == NULL);
    result = delete_medicine_service(newService, "paul", 28);
    assert(strcmp(result, "Medicine not in the list!") == 0);
    add_medicine_service(newService, "piracetam", 60, 10, 50);
    result = update_price_service(newService, "piracetam", 60, 1000);
    assert(result == NULL);
    result = update_price_service(newService, "paul", 28, 100);
    assert(strcmp(result, "Medicine not updated!") == 0);
    result = update_quantity_service(newService, "piracetam", 60, 5000);
    assert(result == NULL);
    result = update_quantity_service(newService, "paul", 28, 100);
    assert(strcmp(result, "Medicine not updated!") == 0);
    Medicine* data = (Medicine*)malloc(100* sizeof(Medicine));
    int size = available_medicines_by_name(newService, "cold", data);
    assert(size == 2);
    //sort_medicines(data, size, 'a');
    free(data);
    data = (Medicine*)malloc(100* sizeof(Medicine));
    size = available_medicines_by_concentration(newService, "2", data);
    assert(size == 6);
    //sort_medicines(data, size, 'b');
    free(data);
    data = (Medicine*)malloc(100* sizeof(Medicine));
    size = medicines_in_short_supply(newService, data, 18);
    assert(size == 3);
    free(data);
    assert(undo_operation_service(newService) == 1);
    assert(redo_operation_service(newService) == 1);
    service_destructor(newService);
}

void test_undo_service() {
    UndoService* newUndoService;
    newUndoService = init_undo_service();
    assert(newUndoService->totalNrOfPerformedOperations == 0);
    assert(newUndoService->historyCapacity == 10);
    assert(newUndoService->currentAction == 0);
    resize_undo_service(newUndoService);
    assert(newUndoService->historyCapacity == 20);
    Repository* newRepository;
    newRepository = init_repository(10);
    save_data(newUndoService, newRepository);
    assert(newUndoService->currentAction == 1);
    assert(undo_operation(newUndoService) == 1);
    assert(newUndoService->currentAction == 0);
    assert(redo_operation(newUndoService) == 1);
    assert(newUndoService->currentAction == 1);
    undo_service_destructor(newUndoService);
}

void run_tests() {
    test_entity();
    test_validators();
    test_repository();
    test_service();
    test_undo_service();
}
