//
// Created by paula on 6/17/2021.
//

#ifndef CAR_LIST_WRITTEN_LIST_H
#define CAR_LIST_WRITTEN_LIST_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T e1, U e2): first{e1}, second{e2} {

    }

    T getFirst() {
        return this->first;
    }

    U getSecond() {
        return this->second;
    }

};

template<typename T, typename U>
class List {
    friend class Pair<T, U>;

private:
    vector<Pair<T, U>> data;

public:
    List();

    void add(T el1, U el2);

    void sortByFirstComponent();

    void sortBySecondComponent();

    void printReverse(ostream &stream);

    ~List();

};

template<typename T, typename U>
List<T, U>::List() = default;

template<typename T, typename U>
void List<T, U>::add(T el1, U el2) {
    Pair<T, U> x(el1, el2);
    this->data.push_back(x);
}

template<typename T, typename U>
void List<T, U>::sortByFirstComponent() {
    if (this->data.size() == 0)
        throw std::runtime_error("List is empty!");

    int i, j;
    for (i=0;i<this->data.size()-1;i++) {
        for(j=i+1;j<this->data.size();j++) {
            if (this->data[i].getFirst().getNumber() > this->data[j].getFirst().getNumber()) {
                Pair<T, U> aux = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = aux;
            }
        }
    }
}

template<typename T, typename U>
void List<T, U>::sortBySecondComponent() {
    if (this->data.size() == 0)
        throw std::runtime_error("List is empty!");

    int i, j;
    for (i=0;i<this->data.size()-1;i++) {
        for(j=i+1;j<this->data.size();j++) {
            if (this->data[i].getSecond() > this->data[j].getSecond()) {
                Pair<T, U> aux = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = aux;
            }
        }
    }
}

template<typename T, typename U>
void List<T, U>::printReverse(ostream &stream) {
//    for (auto& elem : this->data)
//        stream << elem.getFirst().getName() << " " << elem.getFirst().getNumber() << " -> " << elem.getSecond() << "; ";
    for (int index = this->data.size()-1; index >= 0 ; index--)
        stream << this->data[index].getFirst().getName() << " " << this->data[index].getFirst().getNumber() << " -> " << this->data[index].getSecond() << "; ";
    stream << "\n";
}

template<typename TElem1, typename TElem2>
List<TElem1, TElem2>::~List() = default;


#endif //CAR_LIST_WRITTEN_LIST_H
