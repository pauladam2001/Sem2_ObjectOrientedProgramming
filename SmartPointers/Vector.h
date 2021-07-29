//
// Created by daria on 18/06/2021.
//

#ifndef SMARTPOINTERS_VECTOR_H
#define SMARTPOINTERS_VECTOR_H

#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

template<class TElem>
class Vector {
private:
    vector<TElem> data;

public:
    Vector() = default;

    Vector& add(TElem newElement) {
        this->data.push_back(newElement);
        return *this;
    }

    Vector<TElem>& operator-(TElem& elem) {
        for(int i=0; i<this->data.size(); i++){
            if(this->data[i] == elem){
                this->data.erase(this->data.begin() + i);
                return *this;
            }
        }
        throw invalid_argument("Element does not exist!");
    }

    Vector<TElem>& operator=(const Vector<TElem>& otherVector) {
        this->data = otherVector.data;
        return *this;
    }

    typename vector<TElem>::iterator begin(){
        return this->data.begin();
    }
    typename vector<TElem>::iterator end(){
        return this->data.end();
    }

    ~Vector() = default;
};


#endif //SMARTPOINTERS_VECTOR_H
