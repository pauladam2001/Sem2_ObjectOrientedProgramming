//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_DYNARRAY_H
#define A45_PAULADAM2001_DYNARRAY_H


template <class TElem>      //OR typename instead of class

class dynamicArray {
private:

    TElem* elementsArray;
    int capacity;
    int currentNr;

    /// Resize the dynamic array
    void resize() {
        TElem* resizeArray = new TElem[this->capacity * 2];
        for (int index = 0; index < this->capacity; index++) {
            resizeArray[index] = this->elementsArray[index];
        }
        this->capacity *= 2;
        delete[] this->elementsArray;
        this->elementsArray = resizeArray;
    }

public:

    /// Constructor
    dynamicArray() {

    }

    /// Constructor
    /// \param capacity - the maximum capacity of the array
    dynamicArray(int capacity) {
        this->capacity = capacity;
        this->currentNr = 0;
        this->elementsArray = new TElem[this->capacity];
    }

    /// Get the data from the dynamic array
    /// \return - the data from the dynamic array
    TElem* getData() {
        return this->elementsArray;
    }

    /// Get the number of elements in the dynamic array
    /// \return - the current number of elements
    int getSize() {
        return this->currentNr;
    }

    /// Add an element
    /// \param newElem - the element that we will add
    void add(TElem &newElem) {
//        if (this->elementsArray == NULL)
//            return;
        if (this->currentNr == this->capacity)
            resize();
        this->elementsArray[this->currentNr] = newElem;
        this->currentNr++;
    }

    /// Remove an element
    /// \param position - the position from where the element will be removed
    void delete_(int position) {
        this->elementsArray[position] = this->elementsArray[this->currentNr - 1];
        this->currentNr--;
    }

    /// Update an element
    /// \param position - the position where the element that we will update is situated
    /// \param updatedElem - the updated element
    void update(int position, TElem &updatedElem) {
        this->elementsArray[position] = updatedElem;
    }

    /// Get an element from the array
    /// \param position - the position of the element that we will return
    /// \return - the element
    TElem& operator[](int position) {
        return this->elementsArray[position];
    }

//    /// Something like a constructor, I don't really use it
//    /// \param da
//    /// \return
//    dynamicArray& operator=(const dynamicArray &da) {
//        if (this == &da)
//            return *this;
//        this->capacity = da.capacity;
//        this->currentNr = da.currentNr;
//        memcpy(this->elementsArray, da.elementsArray, sizeof(TElem)*da.capacity);
//        return *this;
//    }

    /// Set the number of elements to 0
    void empty() {
        this->currentNr = 0;
    }

    /// Destructor
    ~dynamicArray() {
        delete[] this->elementsArray;
    }
};

//SAU am fi putut scrie functiile in afara clasei (OOP -> Lecture_4 -> DynamicVector.h):
//
//template <typename TElem>
//dynamicArray<TElem>::dynamicArray(int capacity) {
//  this->capacity = capacity;
//  this->currentNr = 0;
//  this->elementsArray = new TElem[this->capacity];
//}


#endif //A45_PAULADAM2001_DYNARRAY_H
