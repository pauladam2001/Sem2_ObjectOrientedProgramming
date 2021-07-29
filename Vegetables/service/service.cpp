//
// Created by paula on 5/20/2021.
//

#include "service.h"
#include <algorithm>

Service::Service(Repository& repository):repository{repository} {

}

vector<Vegetable> Service::getData() {
    return this->repository.getData();
}

Service::~Service() {

}

bool sort_function(Vegetable v1, Vegetable v2) {
    return (v1.getFamily() < v2.getFamily());
}

vector<Vegetable> Service::sort_by_family() {
    vector<Vegetable> data = this->getData();

    sort(data.begin(), data.end(), sort_function);

    return data;
}

vector<string> Service::get_unique_families() {
    vector<Vegetable> data = this->sort_by_family();
    vector<string> families;
    vector<string> uniqueFamilies;

    for (auto &element : data)
        families.push_back(element.getFamily());

    for (auto &element : families) {
        string key = element;
        if (std::count(uniqueFamilies.begin(), uniqueFamilies.end(), key) < 1)
            uniqueFamilies.push_back(element);
    }

    return uniqueFamilies;


//    OR
//    vector<string> families;
//    for(auto & v: this->getAll())
//        families.push_back(v.getFamily());
//
//    vector<string>::iterator it;
//
//    it = unique(families.begin(), families.end());
//    families.resize(distance(families.begin(), it));
//    return families;
}

vector<Vegetable> Service::get_family_vegetables(string family) {
    vector<Vegetable> data;

    for (auto &element: this->getData())
        if (element.getFamily() == family)
            data.push_back(element);

    return data;
}
