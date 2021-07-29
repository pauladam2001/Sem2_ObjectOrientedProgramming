//
// Created by paula on 6/20/2021.
//

#ifndef ENCODER_UML_DIAGRAM_WRITTEN_COMMUNICATION_H
#define ENCODER_UML_DIAGRAM_WRITTEN_COMMUNICATION_H

#include "Encoder.h"
#include <string>
#include <vector>
#include <set>          // container already sorted


class Communication {
private:
    set<string> messages;
    Encoder* encoder{};

public:
    Communication();

    Communication(Encoder* encoder);

    void addMessage(const string& message);

    string communicate();

    ~Communication();
};


#endif //ENCODER_UML_DIAGRAM_WRITTEN_COMMUNICATION_H
