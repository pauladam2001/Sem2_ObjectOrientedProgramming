//
// Created by paul on 6/17/2021.
//

#include "Activity.h"
#include <iostream>

Activity::Activity(string action, string time): action{action}, time{time} {

}

std::ostream &operator<<(ostream &output, const Activity &activity) {
    output << "Activity " << activity.action << " will take place at " << activity.time << ".";
    return output;
}
