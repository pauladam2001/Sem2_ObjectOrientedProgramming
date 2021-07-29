cmake_minimum_required(VERSION 3.17)
project(Channel_UML_Diagram_Written)

set(CMAKE_CXX_STANDARD 14)

add_executable(Channel_UML_Diagram_Written main.cpp channel/Channel.h telephone/Telephone.cpp telephone/Telephone.h)