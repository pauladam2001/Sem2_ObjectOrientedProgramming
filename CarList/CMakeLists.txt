cmake_minimum_required(VERSION 3.17)
project(Car_List_Written)

set(CMAKE_CXX_STANDARD 14)

add_executable(Car_List_Written
        main.cpp
        classes/car.cpp
        classes/car.h
        classes/list.h)