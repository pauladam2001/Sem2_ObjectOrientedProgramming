//
// Created by paula on 6/18/2021.
//

#ifndef COMPLEX_VECTOR_WRITTEN_VECTOR_H
#define COMPLEX_VECTOR_WRITTEN_VECTOR_H

#include <vector>

using namespace std;


template <typename TElem>
class Vector {
private:
    vector<TElem> data;

public:
    Vector(vector<TElem> data):data{data} {

    }

    void printAll(std::ostream& stream) {
        for (const auto& elem : this->data)
            stream << elem << ", ";
        stream<< "\n";
    }

    ~Vector() = default;

};


#endif //COMPLEX_VECTOR_WRITTEN_VECTOR_H
