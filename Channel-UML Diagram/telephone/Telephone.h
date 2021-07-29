//
// Created by paula on 6/18/2021.
//

#ifndef CHANNEL_UML_DIAGRAM_WRITTEN_TELEPHONE_H
#define CHANNEL_UML_DIAGRAM_WRITTEN_TELEPHONE_H

#include <string>
#include "../channel/Channel.h"

using namespace std;


class Telephone : public Channel {
private:
    string number;

public:
    void send(string message) override;
};


class Fax : public Telephone {
    void send(string message);
};

class SMS : public Telephone {
    void send(string message);
};


#endif //CHANNEL_UML_DIAGRAM_WRITTEN_TELEPHONE_H
