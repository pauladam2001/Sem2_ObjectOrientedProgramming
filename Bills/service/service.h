//
// Created by paula on 5/20/2021.
//

#ifndef CARS_SERVICE_H
#define CARS_SERVICE_H

#include "bill.h"
#include "repo.h"

class Service {
private:
    Repository& repository;

public:
    Service(Repository& repository);

    vector<Bill> getData();

    vector<Bill> sort_by_company();

    double unpaid_company_bills(string company);

    ~Service();
};

#endif //CARS_SERVICE_H
