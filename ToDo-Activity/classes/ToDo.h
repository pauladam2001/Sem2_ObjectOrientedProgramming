//
// Created by paul on 6/17/2021.
//

#ifndef TODO_ACTIVITY_WRITTEN_TODO_H
#define TODO_ACTIVITY_WRITTEN_TODO_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename TElem>
class ToDo {
private:
    std::vector<TElem> data;

public:
    ToDo();

    ToDo(const ToDo<TElem>& obj);

    ToDo<TElem> operator +=(const TElem& element);

    typename std::vector<TElem>::iterator begin() {
        return this->data.begin();
    }

    typename std::vector<TElem>::iterator end() {
        return this->data.end();
    }

    void reversePrint(std::ostream& stream);

    ~ToDo();

};

template<typename TElem>
ToDo<TElem>::ToDo() = default;

template<typename TElem>
ToDo<TElem>::ToDo(const ToDo<TElem> &obj) {
    std::copy(obj.data.begin(), obj.data.end(), std::back_inserter(this->data));
}

template<typename TElem>
ToDo<TElem> ToDo<TElem>::operator+=(const TElem &element) {
    this->data.insert(data.begin(), element);
    return *this;
}

template<typename TElem>
void ToDo<TElem>::reversePrint(ostream &stream) {
    vector<TElem> reverse;
    std::copy(this->data.begin(), this->data.end(), std::back_inserter(reverse));
    std::reverse(reverse.begin(), reverse.end());
    for (const auto& elem : reverse)
        stream << elem << '\n';
}

template<typename TElem>
ToDo<TElem>::~ToDo() = default;


#endif //TODO_ACTIVITY_WRITTEN_TODO_H
