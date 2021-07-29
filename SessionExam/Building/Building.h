//
// Created by paula on 6/22/2021.
//

#ifndef E2_PAULADAM2001_1_BUILDING_H
#define E2_PAULADAM2001_1_BUILDING_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Building {
private:
    int id;
    string description;
    string area;
    vector<string> locations;

public:
    Building() = default;

    Building(int id, string description, string area, vector<string> locations);

    int getId();

    string getDescription();

    string getArea();

    vector<string>& getLocations();

    void setDescription(string description);

    void setLocation(vector<string> locations);

    static vector<string> tokenize(string str, char delimiter);

    friend istream& operator>>(istream&, Building&);

    ~Building() = default;
};


#endif //E2_PAULADAM2001_1_BUILDING_H
