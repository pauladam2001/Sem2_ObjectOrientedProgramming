//
// Created by paula on 6/18/2021.
//

#include <stdexcept>
#include "Complex.h"
#include <iostream>

using namespace std;


Complex::Complex() {
    this->real = 0;
    this->imaginary = 0;
}

Complex::Complex(int real, int imaginary): real{real}, imaginary{imaginary} {

}

Complex::Complex(const Complex &number): real{number.real}, imaginary{number.imaginary} {

}

Complex &Complex::operator/(int nr) {
    if (nr == 0)
        throw std::runtime_error("Division by zero!");
    this->real = this->real / nr;
    this->imaginary = this->imaginary / nr;
    return *this;
}

Complex &Complex::operator=(const Complex &number) {
   this->real = number.real;
   this->imaginary = number.imaginary;
   return *this;
}

bool Complex::operator==(const Complex &number) const {
    if (this->real == number.real && this->imaginary == number.imaginary)
        return true;
    return false;
}

int Complex::getReal() {
    return this->real;
}

int Complex::getImaginary() {
    return this->imaginary;
}

std::ostream &operator<<(ostream &output, const Complex &number) {
    output << number.real << "+" << number.imaginary << "i";
    return output;
}
