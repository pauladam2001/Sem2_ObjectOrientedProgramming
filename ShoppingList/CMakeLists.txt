cmake_minimum_required(VERSION 3.17)
project(Shopping_List)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

include_directories(domain)
include_directories(GUI)
include_directories(repository)
include_directories(service)

add_executable(Shopping_List
        domain/item.cpp
        domain/item.h
        GUI/gui.cpp
        GUI/gui.h
        repository/repo.cpp
        repository/repo.h
        service/service.cpp
        service/service.h
        main.cpp)

file(COPY list.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
