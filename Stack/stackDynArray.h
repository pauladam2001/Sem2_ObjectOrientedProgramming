//
// Created by paula on 6/17/2021.
//

#ifndef STACK_WRITTEN_STACKDYNARRAY_H
#define STACK_WRITTEN_STACKDYNARRAY_H

#include <exception>

using namespace std;


template <class TElem>
class Stack {
private:
    TElem* data;
    int maxCapacity;
    int size;

public:
    Stack(int maxCapacity):maxCapacity{maxCapacity}, size{0} {
        this->data = new TElem[this->maxCapacity];
    }

    int getMaxCapacity() {
           return this->maxCapacity;
    }

//    TElem& operator[](int position) {
//        return this->data[position];
//    }

    TElem pop() {
        TElem elem = this->data[size - 1];
        this->size--;
        return elem;
    }

    Stack<TElem>& operator +(const TElem &element) {
        if (this->size == this->maxCapacity)
            throw std::invalid_argument("Stack is full!");

        this->data[this->size] = element;
        this->size++;
        return *this;
    }

    ~Stack() {
        delete[] this->data;
    }

};


#endif //STACK_WRITTEN_STACKDYNARRAY_H
