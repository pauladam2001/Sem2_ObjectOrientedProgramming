cmake_minimum_required(VERSION 3.17)
project(ToDo_Activity_Written)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToDo_Activity_Written
        main.cpp
        classes/Activity.cpp
        classes/Activity.h
        classes/ToDo.h)