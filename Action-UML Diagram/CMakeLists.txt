cmake_minimum_required(VERSION 3.17)
project(Action_UML_Diagram_Written)

set(CMAKE_CXX_STANDARD 14)

add_executable(Action_UML_Diagram_Written main.cpp action/Action.h menu/MenuItem.cpp menu/MenuItem.h)