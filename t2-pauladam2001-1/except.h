//
// Created by paula on 4/26/2021.
//

#ifndef T2_PAULADAM2001_1_EXCEPT_H
#define T2_PAULADAM2001_1_EXCEPT_H

#include <string>


using namespace std;

class CustomException : public std::exception {
protected:

    std::string message;

public:

    explicit CustomException(string exceptionMessage);

    const char* what() const noexcept override;
};

#endif //T2_PAULADAM2001_1_EXCEPT_H
