//
// Created by paula on 6/18/2021.
//

#ifndef ADDER_WRITTEN_ADDER_H
#define ADDER_WRITTEN_ADDER_H

#include <vector>

using namespace std;


template <typename TElem>
class Adder {
private:
    int total;
    vector<TElem> values;

public:
    Adder(int total): total{total} {
        this->values.push_back(total);
    }

    Adder<TElem>& operator +(const TElem &elem) {
        this->values.push_back(elem);
        this->total += elem;
        return *this;
    }

    Adder<TElem>& operator ++() {
        this->total += this->values[this->values.size() - 1];
        this->values.push_back(this->values[this->values.size() - 1]);
        return *this;
    }

    Adder<TElem>& operator --() {
        if (this->values.size() == 0)
            throw runtime_error("No more values!");
        this->total -= this->values[this->values.size() - 1];
        this->values.erase(this->values.end() - 1);
        return *this;
    }

    int sum() {
        return this->total;
    }

};


#endif //ADDER_WRITTEN_ADDER_H
