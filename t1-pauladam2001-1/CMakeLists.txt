cmake_minimum_required(VERSION 3.17)
project(t1_pauladam2001_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(entity)
include_directories(repository)
include_directories(service)
include_directories(ui)

add_executable(t1_pauladam2001_1
        entity/gene.cpp
        entity/gene.h
        repository/repository.cpp
        repository/repository.h
        service/service.cpp
        service/service.h
        ui/userInterface.cpp
        ui/userInterface.h
        start.cpp)
