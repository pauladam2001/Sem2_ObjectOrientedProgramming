//
// Created by paul on 3/15/2021.
//

#ifndef A23_PAULADAM2001_DYNAMICARRAY_H
#define A23_PAULADAM2001_DYNAMICARRAY_H

#include <entity/medicine.h>
#include <stdio.h>
#include <stdlib.h>

typedef Medicine TElem;

typedef struct {
    TElem* array;
    int count;
    int capacity;
} DynamicArray;

DynamicArray init_dynamic_array(int arrayCapacity);

int add(DynamicArray* DynArray, TElem newTElem, int inRepo);

int delete(DynamicArray* DynArray, int position);

int update(DynamicArray* DynArray, TElem newTElem, int position);

void resize(DynamicArray* DynArray);

void dynamic_array_destructor(DynamicArray* DynArray);

#endif //A23_PAULADAM2001_DYNAMICARRAY_H
