//
// Created by paula on 6/22/2021.
//

#ifndef E2_PAULADAM2001_1_REPOSITORY_H
#define E2_PAULADAM2001_1_REPOSITORY_H

#include "../Building/Building.h"
#include "../Ethnologist/Ethnologist.h"
#include <fstream>
#include <vector>


class Repository {
private:
    vector<Ethnologist> ethnologists;
    vector<Building> buildings;

    void load_data_ethnologists();

    void load_data_buildings();

public:
    Repository();

    vector<Ethnologist>& getEthnologists();

    vector<Building>& getBuildings();

    void add_building(Building building);

    void update_building(int id, string decription, vector<string> locations);

    ~Repository() = default;

};


#endif //E2_PAULADAM2001_1_REPOSITORY_H
