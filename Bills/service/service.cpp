//
// Created by paula on 5/20/2021.
//

#include "service.h"
#include <algorithm>

Service::Service(Repository& repository):repository{repository} {

}

vector<Bill> Service::getData() {
    return this->repository.getData();
}

Service::~Service() {

}

bool sort_function(Bill c1, Bill c2) {
    return (c1.getCompany() < c2.getCompany());
}

vector<Bill> Service::sort_by_company() {
    vector<Bill> data = this->getData();

    sort(data.begin(), data.end(), sort_function);

    return data;
}

double Service::unpaid_company_bills(string company) {
    double total = 0;
    for (auto &element : this->getData())
        if (element.getCompany() == company && element.getIsPaid() == "false")
            total += element.getSum();
    return total;
}
