//
// Created by paula on 4/26/2021.
//

#include "except.h"

CustomException::CustomException(string exceptionMessage) {
    this->message = std::move(exceptionMessage);
}

const char *CustomException::what() const noexcept {
    return this->message.c_str();
}
