//
// Created by paula on 5/20/2021.
//

#ifndef CARS_TASK_H
#define CARS_TASK_H

#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string description;
    int duration;
    int priority;

public:
    Task();

    Task(string description, int duration, int priority);

    string getDescription();

    int getDuration();

    int getPriority();

    friend std::istream& operator>>(std::istream&, Task&);

    ~Task();
};

#endif //CARS_TASK_H
