//
// Created by paula on 5/24/2021.
//

#include "service.h"

Service::Service(Repository &repository):repository{repository} {

}

vector<TimeInterval> Service::getData() {
    return this->repository.getData();
}

Service::~Service() {

}

vector<TimeInterval> Service::filter(int probability) {
    vector<TimeInterval> data = this->getData();
    vector<TimeInterval> filteredData;

    for (auto &element:data)
        if (element.getProbability() < probability)
            filteredData.push_back(element);

    return filteredData;
}

vector<TimeInterval> Service::filter_checkbox(string string1, string string2, string string3, string string4, string string5) {
    vector<TimeInterval> data = this->getData();
    vector<TimeInterval> filteredData;

    for (auto &element:data)
        if (element.getDescription() == string1 || element.getDescription() == string2 || element.getDescription() == string3 || element.getDescription() == string4 || element.getDescription() == string5)
            filteredData.push_back(element);

    return filteredData;
}

vector<TimeInterval> Service::filter_both(int probability, string string1, string string2, string string3, string string4, string string5) {
    vector<TimeInterval> data = this->getData();
    vector<TimeInterval> filteredData;

    for (auto &element:data)
        if ((element.getDescription() == string1 || element.getDescription() == string2 || element.getDescription() == string3 || element.getDescription() == string4 || element.getDescription() == string5) && element.getProbability() < probability)
            filteredData.push_back(element);

    return filteredData;
}
