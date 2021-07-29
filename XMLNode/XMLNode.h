//
// Created by paula on 6/18/2021.
//

#ifndef XMLNODE_WRITTEN_XMLNODE_H
#define XMLNODE_WRITTEN_XMLNODE_H

#include <string>
#include <sstream>
#include <vector>
#include "XMLAttribute.h"

using namespace std;


class XMLNode {
private:
    string first;
    string second;
    vector<XMLAttribute> attributes;
    vector<XMLNode> childNodes;

public:
    XMLNode(string first, string second):first{std::move(first)}, second{std::move(second)} {

    }

    string getXMLString() {
        stringstream repr;
        repr << "<" << this->first << ">" << this->second << "</" << this->first << ">";
        return repr.str();
    }

    XMLNode& addAttribute(XMLAttribute attr) {
        this->attributes.push_back(attr);
        return *this;
    }

    XMLNode& addChildNode(XMLNode child) {
        this->childNodes.push_back(child);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, XMLNode n) {
//        os << n.getXMLString();
//        for (auto elem : childNodes) {
//            os << elem;
//        }
//        return os;
        os << n.getXMLString();
        for (auto elem : n.childNodes) {
            for (auto elem2 : n.attributes)
                os << elem;
            os << elem;
        }
        return os;
    }
};


#endif //XMLNODE_WRITTEN_XMLNODE_H
