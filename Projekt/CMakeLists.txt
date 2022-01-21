cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

project(Projekt)

include_directories(include)

add_executable(Projekt src/main.cpp include/daneOPosilkach.h include/posilek.h include/plik.h)

