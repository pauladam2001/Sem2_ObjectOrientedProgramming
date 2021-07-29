//
// Created by paul on 4/4/2021.
//

#include "customExceptions.h"

#include <utility>


CustomException::CustomException(string exceptionMessage) {
    this->message = std::move(exceptionMessage);
}

const char *CustomException::what() const noexcept {
    return this->message.c_str();
}

ValidatorException::ValidatorException(string exceptionMessage) : CustomException(std::move(exceptionMessage)) {
}

RepositoryException::RepositoryException(string exceptionMessage) : CustomException(std::move(exceptionMessage)) {
}
