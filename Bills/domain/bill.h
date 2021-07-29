//
// Created by paula on 5/20/2021.
//

#ifndef CARS_TASK_H
#define CARS_TASK_H

#include <string>
#include <vector>

using namespace std;

class Bill {
private:
    string company;
    string code;
    double sum;
    string isPaid;

public:
    Bill();

    Bill(string company, string code, double sum, string isPaid);

    string getCompany();

    string getCode();

    double getSum();

    string getIsPaid();

    friend std::istream& operator>>(std::istream&, Bill&);

    ~Bill();
};

#endif //CARS_TASK_H
