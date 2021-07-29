//
// Created by paula on 6/18/2021.
//

#ifndef PERSON_MULTIDICTIONARY_WRITTEN_MULTIDICTIONARY_H
#define PERSON_MULTIDICTIONARY_WRITTEN_MULTIDICTIONARY_H

#include <vector>
#include <algorithm>

using namespace std;


template<typename T, typename U>
class MultiDictionary {
private:
    vector<pair<T, U>> data;

public:
    MultiDictionary() = default;

    MultiDictionary& add(T el1, U el2) {
        pair<T, U> newPair(el1, el2);
        this->data.push_back(newPair);
        return *this;
    }

    void print(ostream& stream) {
        for (int index = 0; index < this->data.size(); index++)
            stream << this->data[index].first << " " << this->data[index].second << "; ";
        stream << "\n";
    }

    /// Deletes a pair formed by el1 and el2 (if it exists)
    /// \param el1 - the first element from the pair
    /// \param el2 - the second element from the pair
    /// \throws - runtime_error if the key (el1) does not exist in the MultiDictionary, or if the key exist but its associated value (el2)
    ///           does not exist
    void erase(T el1, U el2) {
        int semKey = 0, semValue = 0;
        int position;
        for (int index = 0; index < this->data.size(); index++) {
            if (this->data[index].first == el1) {
                semKey = 1;
                if (this->data[index].second == el2) {
                    semValue = 1;
                    position = index;
                    break;
                }
            }
        }
        if (semKey == 0)
            throw runtime_error("Key does not exist!");
        if (semKey == 1 && semValue == 0)   //first condition is always true if we're here
            throw runtime_error("Given value does not exist for given key!");
        if (semKey == 1 && semValue == 1) //the if is not really necessary because we're here only if a runtime_error is not thrown
            this->data.erase(this->data.begin() + position);
    }

    int sizeForKey(T el) {
        int total = 0;
        for (int index = 0; index < this->data.size(); index++)
            if (this->data[index].first == el)
                total ++;
        return total;
    }

    ~MultiDictionary() = default;
};


#endif //PERSON_MULTIDICTIONARY_WRITTEN_MULTIDICTIONARY_H
