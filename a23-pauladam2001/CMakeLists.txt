cmake_minimum_required(VERSION 3.17)
project(a23_pauladam2001 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(a23_pauladam2001
        entity/medicine.c
        entity/medicine.h
        controller/service.c
        controller/service.h
        controller/undoService.c
        controller/undoService.h
        repository/repository.c
        repository/repository.h
        ui/userInterface.c
        ui/userInterface.h
        validation/validators.c
        validation/validators.h
        test/tests.c
        test/tests.h
        dynamic_array/dynamicArray.c
        dynamic_array/dynamicArray.h
        start.c)
