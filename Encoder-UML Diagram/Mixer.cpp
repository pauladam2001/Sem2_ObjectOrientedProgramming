//
// Created by paula on 6/20/2021.
//

#include "Mixer.h"


//Mixer::Mixer() {
//    this->encoder1 = new AlienEncoder("");
//    this->encoder2 = new MorseEncoder();
//}

Mixer::Mixer(Encoder *encoder1, Encoder *encoder2) {
    this->encoder1 = encoder1;
    this->encoder2 = encoder2;
}

string Mixer::encode(string message) {
    string encoder1Message = this->encoder1->encode(message);
    string encoder2Message = this->encoder2->encode(message);
    int encoder1MessageSize = encoder1Message.size();
    int encoder2MessageSize = encoder2Message.size();
    string finalString;
    int i = 0, j = 0;
    while (i < encoder1MessageSize && j < encoder2MessageSize) {
        finalString += encoder1Message[i++];
        finalString += encoder2Message[j++];
    }
    while (i < encoder1MessageSize)
        finalString += encoder1Message[i++];
    while (j < encoder2MessageSize)
        finalString += encoder2Message[j++];

    return finalString;
}

Mixer::~Mixer() {
    delete this->encoder1;
    delete this->encoder2;
}
