//
// Created by paula on 6/20/2021.
//

#ifndef ENCODER_UML_DIAGRAM_WRITTEN_MORSEENCODER_H
#define ENCODER_UML_DIAGRAM_WRITTEN_MORSEENCODER_H

#include "Encoder.h"


class MorseEncoder : public Encoder {
public:
    string encode(string message) override;
};


#endif //ENCODER_UML_DIAGRAM_WRITTEN_MORSEENCODER_H
