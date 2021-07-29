cmake_minimum_required(VERSION 3.17)
project(Encoder_UML_Diagram_Written)

set(CMAKE_CXX_STANDARD 14)

add_executable(Encoder_UML_Diagram_Written main.cpp Encoder.h AlienEncoder.cpp AlienEncoder.h Mixer.cpp Mixer.h MorseEncoder.cpp MorseEncoder.h Communication.cpp Communication.h)