cmake_minimum_required(VERSION 3.6)
project(usuariosArquivos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp usuario.cpp usuario.h getch.cpp getch.h)
add_executable(usuariosArquivos ${SOURCE_FILES})