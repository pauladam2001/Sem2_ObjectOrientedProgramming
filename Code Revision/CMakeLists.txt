cmake_minimum_required(VERSION 3.17)
project(Code_Revision)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

add_executable(Code_Revision main.cpp Programmer/Programmer.cpp Programmer/Programmer.h SourceFile/SourceFile.cpp SourceFile/SourceFile.h Observer/Observer.h TableModel/TableModel.cpp TableModel/TableModel.h RepoFiles/Files.cpp RepoFiles/Files.h RepoProgrammers/RepoProgrammers.cpp RepoProgrammers/RepoProgrammers.h ProgrammerWindow/ProgrammerWindow.cpp ProgrammerWindow/ProgrammerWindow.h StatisticsWindow/StatisticsWindow.cpp StatisticsWindow/StatisticsWindow.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})