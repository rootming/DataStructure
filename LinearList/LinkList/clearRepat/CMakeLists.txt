project(clearRepat)
cmake_minimum_required(VERSION 2.8)
set(SRC_LIST main.cpp link.h)
set(CMAKE_CXX_FLAGS "-std=c++11")
add_executable(${PROJECT_NAME} ${SRC_LIST})

