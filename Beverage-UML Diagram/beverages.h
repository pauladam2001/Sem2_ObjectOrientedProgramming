//
// Created by paula on 6/18/2021.
//

#ifndef BEVERAGE_UML_DIAGRAM_WRITTEN_BEVERAGES_H
#define BEVERAGE_UML_DIAGRAM_WRITTEN_BEVERAGES_H

#include <string>

using namespace std;


class Beverage {
private:
    string description;

public:
    explicit Beverage(string description);

    virtual double price() = 0;

    virtual void print();

    string getDescription();

    virtual ~Beverage() = default;

};

class Coffee : public Beverage {
public:
    Coffee();

    double price() override;

    ~Coffee() override = default;
};

class Tea : public Beverage {
public:
    Tea();

    double price() override;

    ~Tea() override = default;
};

class BeverageWithMilk : public Beverage {
private:
    int milkCount;
    Beverage* beverage;

public:
    explicit BeverageWithMilk(int milkCount, Beverage* beverage);

    double price() override;

    void print() override;
};

class BeverageMachine {
public:
    static void prepare(const string& beverageType, int milkCount);
};


#endif //BEVERAGE_UML_DIAGRAM_WRITTEN_BEVERAGES_H
