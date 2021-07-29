//
// Created by paula on 6/22/2021.
//

#ifndef E2_PAULADAM2001_1_SERVICE_H
#define E2_PAULADAM2001_1_SERVICE_H

#include "../Repository/Repository.h"
#include "../Observer/Observer.h"


class Service : public Observable {
private:
    Repository& repo;

public:
    Service(Repository& repo);

    vector<Ethnologist>& getEthnologists();

    vector<Building>& getBuildings();

    vector<Building> getBuiding_by_area(Ethnologist e);

    void add_building(string description, string area, string location);

    void update_building(int id, string description, string location);

    ~Service() = default;
};


#endif //E2_PAULADAM2001_1_SERVICE_H
