//
// Created by paul on 3/15/2021.
//

#include "dynamicArray.h"


DynamicArray init_dynamic_array(int arrayCapacity) {
    DynamicArray dynArray;
    dynArray.capacity = arrayCapacity;
    dynArray.count = 0;
    dynArray.array = (TElem*)malloc(arrayCapacity * sizeof(TElem));

    return dynArray;
}

int add(DynamicArray* DynArray, TElem newTElem, int inRepo) {
    if (DynArray->count == DynArray->capacity) {
        resize(DynArray);
    }
    if (DynArray->count == 0) {
        DynArray->array[DynArray->count++] = newTElem;
        return 1;
    }
    if (inRepo == -1) {
        DynArray->array[DynArray->count++] = newTElem;
    }
    else {
        setQuantityPlus(&DynArray->array[inRepo], newTElem.quantity);
    }
    return 1;
}

int delete(DynamicArray* DynArray, int position) {
    if (position == -1) {
        return 0;
    }
    DynArray->array[position] = DynArray->array[DynArray->count - 1];
    DynArray->count--;
    return 1;
}

int update(DynamicArray* DynArray, TElem newTElem, int position) {
    if (position == -1)
        return 0;
    DynArray->array[position] = newTElem;
    return 1;
}

void resize(DynamicArray* DynArray) {
    DynamicArray* resize = (DynamicArray*)malloc(sizeof(DynamicArray));
    resize->array = (Medicine*)malloc(2 * DynArray->capacity * sizeof(Medicine));
    for (int index = 0; index < DynArray->count; index ++) {
        resize->array[index] = DynArray->array[index];
    }
    DynArray->capacity *= 2;
    free(DynArray->array);
    DynArray->array = resize->array;
}

void dynamic_array_destructor(DynamicArray* DynArray) {
    free(DynArray->array);
}
