//
// Created by paula on 5/21/2021.
//

#include "service.h"

Service::Service(Repository &repository):repository{repository} {

}

vector<Item> Service::getData() {
    return this->repository.getData();
}

void Service::delete_item_service(string category, string name) {
    this->repository.delete_item(category, name);
}

Service::~Service() {

}

vector<Item> Service::filter_by_category(string category) {
    vector<Item> data;
    for (auto &element : this->getData())
        if (element.getCategory() == category)
            data.push_back(element);
    return data;
}
