//
// Created by paul on 3/1/2021.
//

#ifndef A23_PAULADAM2001_SERVICE_H
#define A23_PAULADAM2001_SERVICE_H

#include "repository/repository.h"
#include "undoService.h"


typedef struct {
    Repository* medicineRepository;
    UndoService* undoService;
} Service;


Service* init_service();
/*
 * Creates a new Service
 * Input: None
 * Output: A pointer to an object of type Service
 */

Repository* get_repository(Service* medicineService);
/*
 * Provides access to the repository
 * Input: - medicineService = a pointer to an object of type Service
 * Output: A pointer to an object of type Repository
 */

char* add_medicine_service(Service* medicineService, char* name, int concentration, int quantity, int price);
/*
 * Calls the add_medicine function in the repository
 * Input: - medicineService = a pointer to an object of type Service
 *        - name = the name of the medicine that we want to add
 *        - concentration = the concentration of the medicine that we want to add
 *        - quantity = the quantity of the medicine that we want to add
 *        - price = the price of the medicine that we want to add
 * Output: - NULL, if the operation was successful
 *         - an error message, otherwise (string)
 */

char* delete_medicine_service(Service* medicineService, char* name, int concentration);
/*
 * Calls the delete_medicine function in the repository
 * Input: - medicineService = a pointer to an object of type Service
 *        - name = the name of the medicine that we want to delete
 *        - concentration = the concentration of the medicine that we want to delete
 * Output: - NULL, if the operation was successful
 *         - an error message, otherwise (string)
 */

char* update_price_service(Service* medicineService, char* name, int concentration, int price);
/*
 * Calls the update_price function in the repository
 * Input: - medicineService = a pointer to an object of type Service
 *        - name = the name of the medicine that we want to update
 *        - concentration = the concentration of the medicine that we want to update
 *        - price = the new price of the given medicine
 * Output: - NULL, if the operation was successful
 *         - an error message, otherwise (string)
 */

char* update_quantity_service(Service* medicineService, char* name, int concentration, int quantity);
/*
 * Calls the update_quantity function in the repository
 * Input: - medicineService = a pointer to an object of type Service
 *        - name = the name of the medicine that we want to update
 *        - concentration = the concentration of the medicine that we want to update
 *        - quantity = the new quantity of the given medicine
 * Output: - NULL, if the operation was successful
 *         - an error message, otherwise (string)
 */

int available_medicines_by_name(Service* medicineService, char* string, Medicine *data);
/*
 * Stores in a new array the medicines from the repository that contain the given name
 * Input: - medicineService = a pointer to an object of type Service
 *         - string = the given name
 *         - data = an array of type Medicine
 * Output: The size of the new array
 */

int available_medicines_by_concentration(Service* medicineService, char* string, Medicine *data);
/*
 * Stores in a new array the medicines from the repository that contain the given concentration
 * Input: - medicineService = a pointer to an object of type Service
 *        - string = the given concentration
 *        - data = an array of type Medicine
 * Output: The size of the new array
 */

int available_medicines_by_quantity(Service* medicineService, char* string, Medicine *data);
/*
 * Stores in a new array the medicines from the repository that contain the given quantity
 * Input: - medicineService = a pointer to an object of type Service
 *        - string = the given quantity
 *        - data = an array of type Medicine
 * Output: The size of the new array
 */

void sort_medicines(Medicine data[], int size, char option);
/*
 * Sorts in ascending order a given vector using qsort()
 * Input: - data = the given array
 *        - size = the size of the array
 *        - option = the option introduced by the user
 * Output: None
 */

void sort_medicines_descending(Medicine data[], int size, char option);
/*
 * Sorts in descending order a given vector using qsort()
 * Input: - data = the given array
 *        - size = the size of the array
 *        - option = the option introduced by the user
 * Output: None
 */

int medicines_in_short_supply(Service* medicineService, Medicine *data, int X);
/*
 * Stores in a new array the medicines from the repository that are in short supply (quantity less than X)
 * Input: - medicineService = a pointer to an object of type Service
 *        - data = an array of type Medicine
 *        - X = the value provided by the user
 * Output: The size of the new array
 */

int undo_operation_service(Service* medicineService);
/*
 * Undoes the last performed operation
 * Input: - medicineService = a pointer to an object of type Service
 * Output: - 1, if the undo was successful
 *         - 0, if there are no more operations to undo
 */

int redo_operation_service(Service* medicineService);
/*
 * Redoes the last operation that was undone
 * Input: - medicineService = a pointer to an object of type Service
 * Output: - 1, if the redo was successful
 *         - 0, if there are no more operations to redo
 */

void service_destructor(Service* medicineService);
/*
 * Deallocates the memory used for a Service
 * Input: - medicineService = a pointer to an object of type Service
 * Output: None
 */


#endif //A23_PAULADAM2001_SERVICE_H
