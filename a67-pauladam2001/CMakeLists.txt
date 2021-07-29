cmake_minimum_required(VERSION 3.17)
project(a67_pauladam2001)

set(CMAKE_CXX_STANDARD 14)

include_directories(controller)
include_directories(dynamicArray)
include_directories(entity)
include_directories(repository)
include_directories(test)
include_directories(ui)
include_directories(validation)

add_executable(a67_pauladam2001
        controller/service.cpp
        controller/service.h
        controller/userService.cpp
        controller/userService.h
        dynamicArray/dynamicArray.h
        entity/trenchCoat.cpp
        entity/trenchCoat.h
        repository/repository.cpp
        repository/repository.h
        repository/fileRepository.cpp
        repository/fileRepository.h
        repository/AbstractBasket.h
        repository/CSVBasket.cpp
        repository/CSVBasket.h
        repository/HTMLBasket.cpp
        repository/HTMLBasket.h
        test/tests.cpp
        test/tests.h
        ui/userInterface.cpp
        ui/userInterface.h
        validation/validators.cpp
        validation/validators.h
        exceptions/customExceptions.cpp
        exceptions/customExceptions.h
        start.cpp)
