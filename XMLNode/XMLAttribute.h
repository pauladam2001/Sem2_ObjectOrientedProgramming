//
// Created by paula on 6/18/2021.
//

#ifndef XMLNODE_WRITTEN_XMLATTRIBUTE_H
#define XMLNODE_WRITTEN_XMLATTRIBUTE_H

#include <string>
#include <sstream>
#include <utility>

using namespace std;


class XMLAttribute {
private:
    string first;
    string second;

public:
    XMLAttribute(string first, string second):first{std::move(first)}, second{std::move(second)} {

    }

    string getXMLString() {
        stringstream repr;
        repr << this->first << "=" << this->second << "";
        return repr.str();
    }
};


#endif //XMLNODE_WRITTEN_XMLATTRIBUTE_H
