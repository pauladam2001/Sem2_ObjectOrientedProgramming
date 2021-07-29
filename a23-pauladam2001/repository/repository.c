//
// Created by paul on 3/1/2021.
//

#include "repository.h"
#include <string.h>


Repository* init_repository(int repoCapacity) {
    Repository* newRepository = (Repository*)malloc(sizeof(Repository));

    if (newRepository == NULL) {
        return NULL;
    }

//    newRepository->data.array = (Medicine*)malloc(repoCapacity * sizeof(Medicine));
//
//    if (newRepository->data.array == NULL) {
//        return NULL;
//    }
//
//    newRepository->data.capacity = repoCapacity;
//    newRepository->data.count = 0;

    newRepository->data = init_dynamic_array(repoCapacity);

    add_10_elements(newRepository);

    return newRepository;
}

void add_10_elements(Repository* medicineRepository) {
    add_medicine(medicineRepository, init_medicine("paracetamol", 52, 2, 20));
    add_medicine(medicineRepository, init_medicine("nurofen", 20, 10, 28));
    add_medicine(medicineRepository, init_medicine("nurofen", 25, 3, 35));
    add_medicine(medicineRepository, init_medicine("coldrex", 12, 50, 15));
    add_medicine(medicineRepository, init_medicine("theraflu", 72, 100, 18));
    add_medicine(medicineRepository, init_medicine("debridat", 30, 20, 13));
    add_medicine(medicineRepository, init_medicine("baneocin", 42, 70, 20));
    add_medicine(medicineRepository, init_medicine("aciclovir", 7, 56, 18));
    add_medicine(medicineRepository, init_medicine("nurofen", 30, 18, 40));
    add_medicine(medicineRepository, init_medicine("coldrex", 15, 34, 17));
}

int add_medicine(Repository* medicineRepository, Medicine newMedicine) {
    int inRepo = search_in_repository(medicineRepository, newMedicine.name, newMedicine.concentration);
    return add(&medicineRepository->data, newMedicine, inRepo);
}

int delete_medicine(Repository* medicineRepository, char* name, int concentration) {
    int position = search_in_repository(medicineRepository, name, concentration);
    return delete(&medicineRepository->data, position);
}

int update_price(Repository* medicineRepository, char* name, int concentration, int newPrice) {
    int position = search_in_repository(medicineRepository, name, concentration);
    int quantity = getQuantity(&medicineRepository->data.array[position]);
    Medicine newMedicine = init_medicine(name, concentration, quantity, newPrice);
    return update(&medicineRepository->data, newMedicine, position);
}

int update_quantity(Repository* medicineRepository, char* name, int concentration, int newQuantity) {
    int position = search_in_repository(medicineRepository, name, concentration);
    int price = getPrice(&medicineRepository->data.array[position]);
    Medicine newMedicine = init_medicine(name, concentration, newQuantity, price);
    return update(&medicineRepository->data, newMedicine, position);
}

int search_in_repository(Repository* medicineRepository, char* name, int concentration) {
    int index, result;
    for (index = 0; index < medicineRepository->data.count; index++) {
        char* actual_name = getName(&medicineRepository->data.array[index]);
        result = strcmp(actual_name, name);
        int actual_concentration = getConcentration(&medicineRepository->data.array[index]);
        if (result == 0 && actual_concentration == concentration) {
            return index;
        }
    }
    return -1;
}

DynamicArray get_data(Repository* medicineRepository) {
    DynamicArray newDynamicArray;
    newDynamicArray.count = medicineRepository->data.count;
    newDynamicArray.capacity = medicineRepository->data.capacity;
    newDynamicArray.array = (Medicine*)malloc(newDynamicArray.count * sizeof(Medicine));

//    if(newDynamicArray.array == NULL) {
//        return NULL;
//    }

    for (int index = 0; index < newDynamicArray.count; index ++) {
        newDynamicArray.array[index] = medicineRepository->data.array[index];
    }

    return newDynamicArray;
}

//void get_data_2(Repository* medicineRepository, DynamicArray* undoDynamicArray) {
//    undoDynamicArray->count = medicineRepository->data.count;
//    undoDynamicArray->capacity = medicineRepository->data.capacity;
//    undoDynamicArray->array = (Medicine*)malloc(undoDynamicArray->count * sizeof(Medicine));
//    for (int index = 0; index < undoDynamicArray->count; index ++) {
//        undoDynamicArray->array[index] = medicineRepository->data.array[index];
//    }
//}

void load_data_in_repository(Repository* medicineRepository, DynamicArray* newDynamicArray) {
    dynamic_array_destructor(&medicineRepository->data);
    medicineRepository->data.capacity = newDynamicArray->capacity;
    medicineRepository->data.count = newDynamicArray->count;
    medicineRepository->data.array = (Medicine*)malloc(newDynamicArray->capacity * sizeof(Medicine));

    if (medicineRepository->data.array == NULL) {
        return;
    }

    for (int index = 0; index < newDynamicArray->count; index ++) {
        medicineRepository->data.array[index] = newDynamicArray->array[index];
    }
}

void repository_destructor(Repository* medicineRepository) {
    dynamic_array_destructor(&medicineRepository->data);
    free(medicineRepository);
}
