//
// Created by paul on 6/17/2021.
//

#ifndef TODO_ACTIVITY_WRITTEN_ACTIVITY_H
#define TODO_ACTIVITY_WRITTEN_ACTIVITY_H

#include <string>

using namespace std;


class Activity {
private:
    string action;
    string time;

public:
    Activity(string action, string time);

    friend std::ostream& operator <<(std::ostream& output, const Activity& activity);

};


#endif //TODO_ACTIVITY_WRITTEN_ACTIVITY_H
