//
// Created by paula on 6/20/2021.
//

#ifndef ENCODER_UML_DIAGRAM_WRITTEN_MIXER_H
#define ENCODER_UML_DIAGRAM_WRITTEN_MIXER_H

#include "Encoder.h"
#include "AlienEncoder.h"
#include "MorseEncoder.h"


class Mixer : public Encoder {
private:
    Encoder* encoder1;
    Encoder* encoder2;

public:
//    Mixer();

    Mixer(Encoder* encoder1, Encoder* encoder2);

    string encode(string message) override;

    ~Mixer();
};


#endif //ENCODER_UML_DIAGRAM_WRITTEN_MIXER_H
