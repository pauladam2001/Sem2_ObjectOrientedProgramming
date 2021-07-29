//
// Created by paula on 6/20/2021.
//

#ifndef ENCODER_UML_DIAGRAM_WRITTEN_ALIENENCODER_H
#define ENCODER_UML_DIAGRAM_WRITTEN_ALIENENCODER_H

#include "Encoder.h"


class AlienEncoder : public Encoder {
private:
    string header;

public:
    AlienEncoder(string header);

    string encode(string message) override;
};


#endif //ENCODER_UML_DIAGRAM_WRITTEN_ALIENENCODER_H
