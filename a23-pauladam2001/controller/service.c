//
// Created by paul on 3/1/2021.
//

#include "service.h"
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100


Service* init_service() {
    Service* newService = (Service*)malloc(sizeof(Service));

    if (newService == NULL) {
        return NULL;
    }

    newService->medicineRepository = init_repository(CAPACITY);
    newService->undoService = init_undo_service();

    return newService;
}

Repository* get_repository(Service* medicineService) {
    return medicineService->medicineRepository;
}

char* add_medicine_service(Service* medicineService, char* name, int concentration, int quantity, int price) {
    Medicine newMedicine = init_medicine(name, concentration, quantity, price);
    int result = add_medicine(medicineService->medicineRepository, newMedicine);
    char* message = "Medicine not added!";
    if (result == 0) {
        return message;
    }
    save_data(medicineService->undoService, medicineService->medicineRepository);
    return NULL;
}

char* delete_medicine_service(Service* medicineService, char* name, int concentration) {
    int result = delete_medicine(medicineService->medicineRepository, name, concentration);
    char* message = "Medicine not in the list!";
    if (result == 0) {
        return message;
    }
    save_data(medicineService->undoService, medicineService->medicineRepository);
    return NULL;
}

char* update_price_service(Service* medicineService, char* name, int concentration, int price) {
    int result = update_price(medicineService->medicineRepository, name, concentration, price);
    char* message = "Medicine not updated!";
    if (result == 0) {
        return message;
    }
    save_data(medicineService->undoService, medicineService->medicineRepository);
    return NULL;
}

char* update_quantity_service(Service* medicineService, char* name, int concentration, int quantity) {
    int result = update_quantity(medicineService->medicineRepository, name, concentration, quantity);
    char* message = "Medicine not updated!";
    if (result == 0) {
        return message;
    }
    save_data(medicineService->undoService, medicineService->medicineRepository);
    return NULL;
}

int available_medicines_by_name(Service* medicineService, char* string, Medicine *data) {
    int size = 0;
    for (int index = 0; index < medicineService->medicineRepository->data.count; index++) {
        char* name = getName(&medicineService->medicineRepository->data.array[index]);
        if (strstr(name, string)) {
            data[size++] = medicineService->medicineRepository->data.array[index];
        }
    }
    return size;
}

int available_medicines_by_concentration(Service* medicineService, char* string, Medicine *data) {
    int size = 0;
    for (int index = 0; index < medicineService->medicineRepository->data.count; index++) {
        int concentration_number = getConcentration(&medicineService->medicineRepository->data.array[index]);
        char concentration_string[10];
        itoa(concentration_number, concentration_string, 10);
        if (strstr(concentration_string, string)) {
            data[size++] = medicineService->medicineRepository->data.array[index];
        }
    }
    return size;
}

int available_medicines_by_quantity(Service* medicineService, char* string, Medicine *data) {
    int size = 0;
    for (int index = 0; index < medicineService->medicineRepository->data.count; index++) {
        int quantity_number = getQuantity(&medicineService->medicineRepository->data.array[index]);
        char quantity_string[10];
        itoa(quantity_number, quantity_string, 10);
        if (strstr(quantity_string, string)) {
            data[size++] = medicineService->medicineRepository->data.array[index];
        }
    }
    return size;
}

int comparator_name(const void* p, const void* q) {
    return strcmp(((Medicine*)p)->name, ((Medicine*)q)->name);
}

int comparator_concetration(const void* p, const void* q) {
    return ((Medicine*)p)->concentration - ((Medicine*)q)->concentration;
}

int comparator_quantity(const void* p, const void* q) {
    return ((Medicine*)p)->quantity - ((Medicine*)q)->quantity;
}

int comparator_name_descending(const void* p, const void* q) {
    return strcmp(((Medicine*)q)->name, ((Medicine*)p)->name);
}

int comparator_concetration_descending(const void* p, const void* q) {
    return ((Medicine*)q)->concentration - ((Medicine*)p)->concentration;
}

int comparator_quantity_descending(const void* p, const void* q) {
    return ((Medicine*)q)->quantity - ((Medicine*)p)->quantity;
}

void sort_medicines(Medicine data[], int size, char option) {
    if (option == 'a')
        qsort(data, size, sizeof(Medicine), comparator_name);    //sizeof(Medicine) = size in bytes of each element in the array.
    else if (option == 'b')
        qsort(data, size, sizeof(Medicine), comparator_concetration);
    else
        qsort(data, size, sizeof(Medicine), comparator_quantity);
}

void sort_medicines_descending(Medicine data[], int size, char option) {
    if (option == 'a')
        qsort(data, size, sizeof(Medicine), comparator_name_descending);    //sizeof(Medicine) = size in bytes of each element in the array.
    else if (option == 'b')
        qsort(data, size, sizeof(Medicine), comparator_concetration_descending);
    else
        qsort(data, size, sizeof(Medicine), comparator_quantity_descending);
}

int medicines_in_short_supply(Service* medicineService, Medicine *data, int X) {
    int size = 0;
    for (int index = 0; index < medicineService->medicineRepository->data.count; index++) {
        int quantity = getQuantity(&medicineService->medicineRepository->data.array[index]);
        if (quantity < X) {
            data[size++] = medicineService->medicineRepository->data.array[index];
        }
    }
    return size;
}

int undo_operation_service(Service* medicineService) {
    int result = undo_operation(medicineService->undoService);
    if (result) {
        load_data_in_repository(medicineService->medicineRepository, get_current_array(medicineService->undoService));
    }
    return result;
}

int redo_operation_service(Service* medicineService) {
    int result = redo_operation(medicineService->undoService);
    if (result) {
        load_data_in_repository(medicineService->medicineRepository, get_current_array(medicineService->undoService));
    }
    return result;
}

void service_destructor(Service* medicineService) {
    undo_service_destructor(medicineService->undoService);
    repository_destructor(medicineService->medicineRepository);
    free(medicineService);
}
