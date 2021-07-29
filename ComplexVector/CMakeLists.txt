cmake_minimum_required(VERSION 3.17)
project(Complex_Vector_written)

set(CMAKE_CXX_STANDARD 14)

add_executable(Complex_Vector_written
        main.cpp
        classes/Complex.cpp
        classes/Complex.h
        classes/vector.h)