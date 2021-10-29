cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

project(matrixApp)

include_directories(../matrixLib/include)

add_executable(matrixApp main.cpp)

target_link_libraries(matrixApp MacLibLib)
