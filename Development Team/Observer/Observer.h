//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_OBSERVER_H
#define DEVELOPMENT_TEAM_OBSERVER_H

#include <vector>
#include <algorithm>

using namespace std;


class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};


class Observable {
private:
    vector<Observer*> observers;

public:
    void addObserver(Observer *obs) {
        this->observers.push_back(obs);
    }

    void removeObserver(Observer* obs) {
        auto it = std::find(this->observers.begin(), this->observers.end(), obs);
        if (it != this->observers.end())
            this->observers.erase(it);
    }

    void notify () {
        for (auto obs : this->observers)
            obs->update();
    }
};


#endif //DEVELOPMENT_TEAM_OBSERVER_H
