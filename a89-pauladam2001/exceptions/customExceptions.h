//
// Created by paul on 4/4/2021.
//

#ifndef A67_PAULADAM2001_CUSTOMEXCEPTIONS_H
#define A67_PAULADAM2001_CUSTOMEXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;


class CustomException : public std::exception {
protected:

    std::string message;

public:

    explicit CustomException(string exceptionMessage);

    const char* what() const noexcept override;
};

class ValidatorException : public CustomException {
public:

    explicit ValidatorException(string exceptionMessage);
};

class RepositoryException : public CustomException {
public:

    explicit RepositoryException(string exceptionMessage);
};


#endif //A67_PAULADAM2001_CUSTOMEXCEPTIONS_H
