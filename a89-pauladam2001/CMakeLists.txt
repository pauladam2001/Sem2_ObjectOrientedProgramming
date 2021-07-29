cmake_minimum_required(VERSION 3.17)
project(a89_pauladam2001)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)


include_directories(controller)
include_directories(dynamicArray)
include_directories(entity)
include_directories(exceptions)
include_directories(repository)
include_directories(test)
include_directories(ui)
include_directories(validation)

add_executable(a89_pauladam2001
        controller/service.cpp
        controller/service.h
        controller/userService.cpp
        controller/userService.h
        dynamicArray/dynamicArray.h
        entity/trenchCoat.cpp
        entity/trenchCoat.h
        exceptions/customExceptions.cpp
        exceptions/customExceptions.h
        repository/AbstractBasket.h
        repository/CSVBasket.cpp
        repository/CSVBasket.h
        repository/fileRepository.cpp
        repository/fileRepository.h
        repository/HTMLBasket.cpp
        repository/HTMLBasket.h
        repository/repository.cpp
        repository/repository.h
        test/tests.cpp
        test/tests.h
        ui/userInterface.cpp
        ui/userInterface.h
        ui/GUI.cpp
        ui/GUI.h
        validation/validators.cpp
        validation/validators.h
        start.cpp)

file(COPY data.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY basket.csv
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY basket.html
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
