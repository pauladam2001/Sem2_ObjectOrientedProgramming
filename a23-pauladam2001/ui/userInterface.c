//
// Created by paul on 3/1/2021.
//

#include "userInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


userInterface* init_userInterface() {
    userInterface* newUserInterface = (userInterface*)malloc(sizeof(userInterface));

    if (newUserInterface == NULL) {
        return NULL;
    }

    newUserInterface->medicineService = init_service();

    return newUserInterface;
}

void print_medicines(userInterface* interface) {
    Repository* repo = get_repository(interface->medicineService);
    char string[100];
    for (int index = 0; index < repo->data.count; index++) {
        to_string(repo->data.array[index], string);
        printf("%s", string);
        printf("%s", "\n");
    }
}

void print_array(Medicine* data, int size) {
    char string[100];
    printf("%s", "\n");
    for (int index = 0; index < size; index++) {
        to_string(data[index],string);
        printf("%s", string);
        printf("%s", "\n");
    }
}

void add_medicine_ui(userInterface* interface) {
    char name[100], concentration[100], quantity[100], price[100];
    printf("%s", "Name:");
    scanf("%s", name);
    printf("%s", "Concentration:");
    scanf("%s", concentration);
    printf("%s", "Quantity:");
    scanf("%s", quantity);
    printf("%s", "Price:");
    scanf("%s", price);

    if (validate_string(name) && validate_int(concentration) && validate_int(quantity) && validate_int(price)) {
        int concentrationNumber = atoi(concentration);
        int quantityNumber = atoi(quantity);
        int priceNumber = atoi(price);

        char* result = add_medicine_service(interface->medicineService, name, concentrationNumber, quantityNumber, priceNumber);
        if (result != NULL)
            printf("%s\n", result);
        else
            printf("%s","Medicine added!\n");
    }
    else {
        printf("%s", "Invalid types for parameters!\n");
    }

}

void delete_medicine_ui(userInterface* interface) {
    char name[100], concentration[100];
    printf("%s", "Name:");
    scanf("%s", name);
    printf("%s", "Concentration:");
    scanf("%s", concentration);

    if (validate_string(name) && validate_int(concentration)) {
        int concentrationNumber = atoi(concentration);

        char* result = delete_medicine_service(interface->medicineService, name, concentrationNumber);
        if (result !=NULL)
            printf("%s\n", result);
        else
            printf("%s", "Medicine deleted!\n");
    }
    else {
        printf("%s", "Invalid types for parameters!\n");
    }
}

void update_medicine_ui(userInterface* interface) {
    printf("\na. Update quantity;");
    printf("\nb. Update price");
    char name[100], concentration[100], quantity[100], price[100], option;
    printf("%s", "\nYour option: ");
    scanf(" %c", &option);              //space in front of %c, otherwise it doesn't work
    if (option == 'a') {
        printf("%s", "Name:");
        scanf("%s", name);
        printf("%s", "Concentration:");
        scanf("%s", concentration);
        printf("%s", "Quantity:");
        scanf("%s", quantity);

        if (validate_string(name) && validate_int(concentration) && validate_int(quantity)) {
            int concentrationNumber = atoi(concentration);
            int quantityNumber = atoi(quantity);

            char* result = update_quantity_service(interface->medicineService, name, concentrationNumber, quantityNumber);
            if (result !=NULL)
                printf("%s\n", result);
            else
                printf("%s", "Medicine updated!\n");
        }
        else {
            printf("%s", "Invalid types for parameters!\n");
        }
    }
    else if (option == 'b') {
        printf("%s", "Name:");
        scanf("%s", name);
        printf("%s", "Concentration:");
        scanf("%s", concentration);
        printf("%s", "Price:");
        scanf("%s", price);

        if (validate_string(name) && validate_int(concentration) && validate_int(price)) {
            int concentrationNumber = atoi(concentration);
            int priceNumber = atoi(price);

            char* result = update_price_service(interface->medicineService, name, concentrationNumber, priceNumber);
            if (result !=NULL)
                printf("%s\n", result);
            else
                printf("%s", "Medicine updated!\n");
        }
        else {
            printf("%s", "Invalid types for parameters!\n");
        }
    }
    else
        printf("\nInvalid command!");
}

void available_medicines_containing_given_string_sorted(userInterface* interface) {
    void (*sort_medicines_asc)(Medicine*, int, char) = &sort_medicines;
    void (*sort_medicines_desc)(Medicine*, int, char) = &sort_medicines_descending;
    int (*available_med_name)(Service*, char*, Medicine*) = &available_medicines_by_name;
    int (*available_med_concentration)(Service*, char*, Medicine*) = &available_medicines_by_concentration;
    int (*available_med_quantity)(Service*, char*, Medicine*) = &available_medicines_by_quantity;

    Medicine* data = (Medicine*)malloc(100* sizeof(Medicine));
    int size;
    char string[100], empty[50];

    printf("\na. Sort by name;");
    printf("\nb. Sort by concentration;");
    printf("\nc. Sort by quantity.");
    char option;
    printf("%s", "\nYour option:");
    scanf(" %c", &option);              //space in front of %c, otherwise it doesn't work
    char sortType;
    printf("\na. Sort ascending;");
    printf("\nb. Sort descending.");
    printf("%s", "\nYour option:");
    scanf(" %c", &sortType);
    if (option == 'a') {
        printf("%s", "\nName (if you want an empty string, just press enter):\n");
        gets_s(empty, sizeof(empty));
        fgets(string, sizeof(string), stdin);
        string[strlen(string) - 1] = '\0';
        if (strcmp(string, "") == 0) {
            if (sortType == 'b')
                //sort_medicines_descending(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
                (*sort_medicines_desc)(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
            else
                //sort_medicines(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
                (*sort_medicines_asc)(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
            print_medicines(interface);
            return;
        }
    }
    else if (option == 'b') {
        printf("%s", "Concentration (if you want an empty string, just press enter):\n");
        gets_s(empty, sizeof(empty));
        fgets(string, sizeof(string), stdin);
        string[strlen(string) - 1] = '\0';
        if (strcmp(string, "") == 0) {
            if (sortType == 'b')
                //sort_medicines_descending(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
                (*sort_medicines_desc)(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
            else
                //sort_medicines(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
                (*sort_medicines_asc)(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
            print_medicines(interface);
            return;
        }
    }
    else if (option == 'c') {
        printf("%s", "Quantity (if you want an empty string, just press enter):\n");
        gets_s(empty, sizeof(empty));
        fgets(string, sizeof(string), stdin);
        string[strlen(string) - 1] = '\0';
        if (strcmp(string, "") == 0) {
            if (sortType == 'b')
                //sort_medicines_descending(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
                (*sort_medicines_desc)(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
            else
                //sort_medicines(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
                (*sort_medicines_asc)(get_repository(interface->medicineService)->data.array, get_repository(interface->medicineService)->data.count, option);
            print_medicines(interface);
            return;
        }
    }
    else {
        printf("\nInvalid command!");
        return;
    }

    if (option == 'a')
        //size = available_medicines_by_name(interface->medicineService, string, data);
        size = (*available_med_name)(interface->medicineService, string, data);
    else if (option == 'b')
        //size = available_medicines_by_concentration(interface->medicineService, string, data);
        size = (*available_med_concentration)(interface->medicineService, string, data);
    else
        //size = available_medicines_by_quantity(interface->medicineService, string, data);
        size = (*available_med_quantity)(interface->medicineService, string, data);

    if (size <=0)
        printf("%s", "No medicines matching the given string!\n");
    else if (size > 0) {
        if (sortType == 'a')
            //sort_medicines(data, size, option);
            (*sort_medicines_asc)(data, size, option);
        else
            //sort_medicines_descending(data, size, option);
            (*sort_medicines_desc)(data, size, option);
        print_array(data, size);
    }

    free(data);
}

void see_medicines_in_short_supply(userInterface* interface) {
    Medicine* data = (Medicine*)malloc(100* sizeof(Medicine));
    char X[10];
    int X_int, size;
    printf("%s", "Introduce X:");
    scanf("%s", X);
    if (validate_int(X)){
        X_int = atoi(X);
    }
    else {
        printf("%s", "X needs to be an integer!");
        return;
    }
    size = medicines_in_short_supply(interface->medicineService, data, X_int);
    if (size <= 0 ) {
        printf("%s", "No medicines in short supply!\n");
    }
    else {
        print_array(data, size);
    }
    free(data);
}

void undo_ui(userInterface* interface) {
    int result = undo_operation_service(interface->medicineService);
    if (result) {
        printf("%s", "Undo done successfully!\n");
    }
    else {
        printf("%s", "No more operations to undo!\n");
    }
}

void redo_ui(userInterface* interface) {
    int result = redo_operation_service(interface->medicineService);
    if (result) {
        printf("%s", "Redo done successfully!\n");
    }
    else {
        printf("%s", "No more operations to redo!\n");
    }
}

void print_menu() {
    printf("\n1. Print all medicines;");
    printf("\n2. Add a medicine;");
    printf("\n3. Delete a medicine;");
    printf("\n4. Update a medicine;");
    printf("\n5. See all available medicines containing a given string, sorted ascending by medicine name, concentration or quantity;");
    printf("\n6. See those medicines that are in short suply (quantity less than X, where the value of X is user-provided);");
    printf("\n7. Undo;");
    printf("\n8. Redo;");
    printf("\n0. Exit program.");
    printf("\n\n Your option:");
}

void start_program(userInterface* interface) {
    char option;

    do {
        print_menu();
        scanf(" %c", &option);

        switch (option) {
            case '0': {
                printf("\nSee you later!");
                break;
            }
            case '1': {
                print_medicines(interface);
                break;
            }
            case '2': {
                add_medicine_ui(interface);
                break;
            }
            case '3': {
                delete_medicine_ui(interface);
                break;
            }
            case '4': {
                update_medicine_ui(interface);
                break;
            }
            case '5': {
                available_medicines_containing_given_string_sorted(interface);
                break;
            }
            case '6': {
                see_medicines_in_short_supply(interface);
                break;
            }
            case '7': {
                undo_ui(interface);
                break;
            }
            case '8': {
                redo_ui(interface);
                break;
            }
            default: {
                printf("\nThis is not a command!\n");
                break;
            }
        }
    } while (option != '0');
}

void userInterface_destructor(userInterface* interface) {
    service_destructor(interface->medicineService);
    free(interface);
}
