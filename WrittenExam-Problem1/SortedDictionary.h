//
// Created by paula on 6/22/2021.
//

#ifndef PROBLEM1_SORTEDDICTIONARY_H
#define PROBLEM1_SORTEDDICTIONARY_H

#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;


template<typename T, typename U>
class SortedDictionary {
private:
    vector<pair<T, U>> data;

public:
    SortedDictionary() = default;

    SortedDictionary& put(T el1, U el2) {
        pair<T, U> newPair(el1, el2);

        for (int i=0;i<this->data.size();i++)
            if (this->data[i].first == newPair.first)
                throw runtime_error("Element already exists!");

        this->data.push_back(newPair);

        for (int i=0;i<this->data.size()-1;i++) {
            for (int j=i+1;j<this->data.size();j++) {
                if (this->data[i].first > this->data[j].first) {
                    pair<T, U> auxPair(this->data[i].first, this->data[i].second);
                    this->data[i] = this->data[j];
                    this->data[j] = auxPair;
                }
            }
        }

        return *this;
    }

    void print(ostream& stream) {
        for (int index = 0; index < this->data.size(); index ++)
            stream << this->data[index].first << " " << this->data[index].second << "; ";
        stream << "\n";
    }


    /// Deletes the second component of the first element from the SortedDictionary and returns it
    /// \return - the second component of the first element from the SortedDictionary  (type U)
    U eraseFirst() {
        pair<T, U> newPair(this->data[0].first, this->data[0].second);
        this->data.erase(this->data.begin());
        return newPair.second;
    }

    int size() {
        return this->data.size();
    }

    ~SortedDictionary() = default;
};


#endif //PROBLEM1_SORTEDDICTIONARY_H
