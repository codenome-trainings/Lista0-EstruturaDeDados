cmake_minimum_required(VERSION 3.6)
project(ASCII)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ascii.cpp ascii.h getch.h getch.cpp)
add_executable(exercicio1 ${SOURCE_FILES})