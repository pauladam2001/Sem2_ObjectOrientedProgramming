//
// Created by paula on 6/20/2021.
//

#include "MorseEncoder.h"


string MorseEncoder::encode(string message) {
    for (char &i : message)
        i = '.';
    return message;
}
