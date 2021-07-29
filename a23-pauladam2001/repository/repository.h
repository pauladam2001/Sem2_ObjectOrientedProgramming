//
// Created by paul on 3/1/2021.
//

#ifndef A23_PAULADAM2001_REPOSITORY_H
#define A23_PAULADAM2001_REPOSITORY_H

#include <entity/medicine.h>
#include <dynamic_array/dynamicArray.h>
#include <stdio.h>
#include <stdlib.h>


//typedef struct {
//    Medicine* array;
//    int count;
//    int capacity;
//} DynamicArray;

typedef struct {
    DynamicArray data;
} Repository;


Repository* init_repository(int repoCapacity);
/*
 * Creates a new Repository
 * Input: - repoCapacity = the maximum capacity of the repository
 * Output: A pointer to an object of type Repository
 */

void add_10_elements(Repository* medicineRepository);
/*
 * Adds 10 elements to the array at program startup
 * Input: - medicineRepository = a pointer to an object of type Repository
 * Output: None
 */

int add_medicine(Repository* medicineRepository, Medicine newMedicine);
/*
 * Adds a medicine to the repository
 * Input: - medicineRepository = a pointer to an object of type Repository
 *        - newMedicine = an object of type Medicine
 * Output: - 1 (operation is always successful because if the medicine is already in repository we increase its quantity)
 */

int delete_medicine(Repository* medicineRepository, char* name, int concentration);
/*
 * Deletes a medicine from the repository
 * Input: - medicineRepository = a pointer to an object of type Repository
 *        - name = the name of the medicine that we want to remove
 *        - concentration = the concentration of the medicine that we want to remove
 * Output: - 1, if the operation was successful
 *         - 0, otherwise
 */

int update_price(Repository* medicineRepository, char* name, int concentration, int newPrice);
/*
 * Updates the price of a given medicine
 * Input: - medicineRepository = a pointer to an object of type Repository
 *        - name = the name of the medicine that we want to update
 *        - concentration = the concentration of the medicine that we want to update
 *        - newPrice = the new price of the given medicine
 * Output: - 1, if the operation was successful
 *         - 0, otherwise
 */

int update_quantity(Repository* medicineRepository, char* name, int concentration, int newQuantity);
/*
 * Updates the quantity of a given medicine
 * Input: - medicineRepository = a pointer to an object of type Repository
 *        - name = the name of the medicine that we want to update
 *        - concentration = the concentration of the medicine that we want to update
 *        - newQuantity = the new quantity of the given medicine
 * Output: - 1, if the operation was successful
 *         - 0, otherwise
 */

int search_in_repository(Repository* medicineRepository, char* name, int concentration);
/*
 *  Searches if a given medicine is in repository
 * Input: - medicineRepository = a pointer to an object of type Repository
 *        - name = the name of the medicine that we want to find
 *        - concentration = the concentration of the medicine that we want to find
 * Output: - the position where the medicine is found in the array, if the operation was successful
 *         - -1, otherwise
 */

DynamicArray get_data(Repository* medicineRepository);
/*
 * Returns a copy (deep) of the data from the repository
 * Input: - medicineRepository = a pointer to an object of type Repository
 * Output: A DynamicArray object (copy (deep) of all the data from the repository)
 */

//void get_data_2(Repository* medicineRepository, DynamicArray* undoDynamicArray);

void load_data_in_repository(Repository* medicineRepository, DynamicArray* newDynamicArray);
/*
 * Input: - medicineRepository = a pointer to an object of type Repository
 *        - newDynamicArray = a pointer to an object of type DynamicArray, which will be the 'new' repository
 * Output: None
 */

void repository_destructor(Repository* medicineRepository);
/*
 * Deallocates the memory used for a Repository
 * Input: - medicineRepository = a pointer to an object of type Repository
 * Output: None
 */


#endif //A23_PAULADAM2001_REPOSITORY_H
