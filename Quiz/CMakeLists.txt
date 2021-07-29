cmake_minimum_required(VERSION 3.17)
project(Quiz)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

add_executable(Quiz main.cpp Observer/Observer.h TableModel/TableModel.h TableModel/TableModel.cpp Question/Question.cpp Question/Question.h Participant/Participant.cpp Participant/Participant.h Repository/RepoParticipants.cpp Repository/RepoParticipants.h Repository/RepoQuestions.cpp Repository/RepoQuestions.h TableModel/TableModelPresenter.cpp TableModel/TableModelPresenter.h PresenterWindow/PresenterWindow.cpp PresenterWindow/PresenterWindow.h ParticipantWindow/ParticipantWindow.cpp ParticipantWindow/ParticipantWindow.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})