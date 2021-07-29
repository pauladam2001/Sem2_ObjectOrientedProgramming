//
// Created by paul on 3/1/2021.
//

#include "medicine.h"
#include <string.h>
#include <stdio.h>

Medicine init_medicine(char* name, int concentration, int quantity, int price) {
    Medicine newMedicine;

    strcpy(newMedicine.name, name);
    newMedicine.concentration = concentration;
    newMedicine.quantity = quantity;
    newMedicine.price = price;

    return newMedicine;
}

void to_string(Medicine med, char string[]) {       //sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    sprintf(string, "Name:%s, Concentration:%d, Quantity:%d, Price:%d", med.name, med.concentration, med.quantity, med.price);
}

char* getName(Medicine* med) {
    return med->name;
}

int getConcentration(Medicine* med) {
    return med->concentration;
}

int getQuantity(Medicine* med) {
    return med->quantity;
}

int getPrice(Medicine* med) {
    return med->price;
}

void setQuantityPlus(Medicine* med, int newQuantity) {
    med->quantity = med->quantity + newQuantity;
}

void setQuantity(Medicine* med, int newQuantity) {
    med->quantity = newQuantity;
}

void setPrice(Medicine* med, int newPrice) {
    med->price = newPrice;
}
