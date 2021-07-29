cmake_minimum_required(VERSION 3.17)
project(Development_Team)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

add_executable(Development_Team main.cpp Member/Member.cpp Member/Member.h Issue/Issue.cpp Issue/Issue.h Observer/Observer.h Repository/Repository.cpp Repository/Repository.h Service/Service.cpp Service/Service.h MemberWindow/MemberWindow.cpp MemberWindow/MemberWindow.h TableModel/TableModel.cpp TableModel/TableModel.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})