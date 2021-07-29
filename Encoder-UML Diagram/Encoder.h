//
// Created by paula on 6/20/2021.
//

#ifndef ENCODER_UML_DIAGRAM_WRITTEN_ENCODER_H
#define ENCODER_UML_DIAGRAM_WRITTEN_ENCODER_H

#include <string>

using namespace std;


class Encoder {
public:
    virtual string encode(string message) = 0;
};


#endif //ENCODER_UML_DIAGRAM_WRITTEN_ENCODER_H
