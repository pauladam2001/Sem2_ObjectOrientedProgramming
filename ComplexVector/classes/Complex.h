//
// Created by paula on 6/18/2021.
//

#ifndef COMPLEX_VECTOR_WRITTEN_COMPLEX_H
#define COMPLEX_VECTOR_WRITTEN_COMPLEX_H


class Complex {
private:
    int real;
    int imaginary;

public:
    Complex();

    Complex(int real, int imaginary);

    Complex(const Complex& number);

    Complex& operator /(int nr);

    Complex& operator =(const Complex& number);

    bool operator ==(const Complex& number) const;

    friend std::ostream& operator <<(std::ostream& output, const Complex& number);

    int getReal();

    int getImaginary();
};


#endif //COMPLEX_VECTOR_WRITTEN_COMPLEX_H
