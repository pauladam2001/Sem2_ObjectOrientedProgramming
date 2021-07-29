cmake_minimum_required(VERSION 3.17)
project(t2_pauladam2001_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2_pauladam2001_1
        bmi.cpp
        bmi.h
        bp.cpp
        bp.h
        measurement.h
        person.cpp
        person.h
        ui.cpp
        ui.h
        except.h
        except.cpp
        start.cpp)
