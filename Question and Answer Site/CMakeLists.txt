cmake_minimum_required(VERSION 3.17)
project(Question_and_answer_site)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Charts Qt5::Gui Qt5::Widgets)

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(Observer)
include_directories(UserWindow)
include_directories(TableModel)

add_executable(Question_and_answer_site main.cpp Domain/User.cpp Domain/User.h Domain/Question.cpp Domain/Question.h Domain/Answer.cpp Domain/Answer.h Repository/UserRepo.cpp Repository/UserRepo.h Repository/AnswerRepo.cpp Repository/AnswerRepo.h Repository/QuestionRepo.cpp Repository/QuestionRepo.h Service/Service.cpp Service/Service.h TableModel/TableModel.cpp TableModel/TableModel.h Observer/Observer.h UserWindow/UserWindow.cpp UserWindow/UserWindow.h)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})