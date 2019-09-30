# cmake_minimum_required(VERSION <specify CMake version here>)
project(TTA)
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

add_executable(TTA main.cpp Player.cpp Player.h)
add_subdirectory(tests)