//
// Created by paula on 5/24/2021.
//

#ifndef T3_PAULADAM2001_WEATHER_H
#define T3_PAULADAM2001_WEATHER_H

#include <string>
#include <vector>

using namespace std;

class TimeInterval {
private:
    int startHour;
    int endHour;
    int probability;
    string description;

public:
    TimeInterval();

    TimeInterval(int start, int end, int prob, string desc);

    int getStartHour();

    int getEndHour();

    int getProbability();

    string getDescription();

    friend std::istream& operator>>(std::istream&, TimeInterval&);

    ~TimeInterval();
};

#endif //T3_PAULADAM2001_WEATHER_H
