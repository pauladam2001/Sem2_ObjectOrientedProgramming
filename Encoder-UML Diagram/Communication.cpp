//
// Created by paula on 6/20/2021.
//

#include "Communication.h"


Communication::Communication() = default;

Communication::Communication(Encoder *encoder) {
    this->encoder = encoder;
}

void Communication::addMessage(const string &message) {
    this->messages.insert(message);
}

string Communication::communicate() {
    string finalString;
    for (const auto& m : this->messages)
        finalString += " " + this->encoder->encode(m);
    return finalString;
}

Communication::~Communication() {
    delete this->encoder;
}
