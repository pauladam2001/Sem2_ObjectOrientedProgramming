//
// Created by paula on 6/20/2021.
//

#include "AlienEncoder.h"


AlienEncoder::AlienEncoder(string header): header{std::move(header)} {

}

string AlienEncoder::encode(string message) {
    message = message + this->header;
    return message;
}
