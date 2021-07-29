//
// Created by paula on 6/22/2021.
//

#include "Service.h"

Service::Service(Repository &repo): repo{repo} {

}

vector<Ethnologist> &Service::getEthnologists() {
    return this->repo.getEthnologists();
}

vector<Building> &Service::getBuildings() {
    return this->repo.getBuildings();
}

vector<Building> Service::getBuiding_by_area(Ethnologist e) {
    vector<Building> sortedBuildingsFinal;
    for (auto& b : this->getBuildings())
        if (b.getArea() == e.getArea())
            sortedBuildingsFinal.push_back(b);

    vector<Building> allBuildingsSorted(this->getBuildings());
    for (int i=0; i < allBuildingsSorted.size(); i++)
        for (int j=i+1; j < allBuildingsSorted.size() - 1; j++)
            if (allBuildingsSorted[i].getArea() > allBuildingsSorted[j].getArea())
                swap(allBuildingsSorted[i], allBuildingsSorted[j]);

    for (auto& b : allBuildingsSorted)
        if (b.getArea() != e.getArea() && b.getArea() != "office")
            sortedBuildingsFinal.push_back(b);

    for (auto& b : allBuildingsSorted)
        if (b.getArea() == "office")
            sortedBuildingsFinal.push_back(b);

    return sortedBuildingsFinal;
}

void Service::add_building(string description, string area, string location) {
    vector<string> locations;
    stringstream ss(location);
    string token;                                       // getting the locations
    while (getline(ss, token, ' '))
        locations.push_back(token);

    int sem = 1;
    vector<Building> buildings = this->getBuildings();
    for(auto &building : buildings)                         // checking overlaps
        for(auto &sector : building.getLocations())
            if(std::find(locations.begin(), locations.end(), sector) != locations.end())        // means that we found an overlap
                sem = 0;

    if (sem == 0)
        throw std::exception();

    sem = 1;
    for (int index = 0; index < locations.size() - 1; index++) {
        string loc1 = locations[index];
        string loc2 = locations[index + 1];
        if (!((loc1[0] == loc2[0] && loc1[1] != loc2[1]) || (loc1[1] == loc2[1] && loc1[0] != loc2[0])))
            sem = 0;
    }

    if (sem == 0)
        throw std::exception();

    int id = this->getBuildings().size();
    Building buildingToAdd(id, description, area, locations);
    this->repo.add_building(buildingToAdd);
    this->notify();
}

void Service::update_building(int id, string description, string location) {
    vector<string> locations;
    stringstream ss(location);
    string token;                                       // getting the locations
    while (getline(ss, token, ' '))
        locations.push_back(token);

    int sem = 1;
    vector<Building> buildings = this->getBuildings();
    for(auto &building : buildings)                         // checking overlaps
        if (building.getId() != id)
            for(auto &sector : building.getLocations())
                if(std::find(locations.begin(), locations.end(), sector) != locations.end())        // means that we found an overlap
                    sem = 0;

    if (sem == 0)
        throw std::exception();

    sem = 1;
    for (int index = 0; index < locations.size() - 1; index++) {
        string loc1 = locations[index];
        string loc2 = locations[index + 1];
        if (!((loc1[0] == loc2[0] && loc1[1] != loc2[1]) || (loc1[1] == loc2[1] && loc1[0] != loc2[0])))
            sem = 0;
    }

    if (sem == 0)
        throw std::exception();

    this->repo.update_building(id, description, locations);
    this->notify();
}
