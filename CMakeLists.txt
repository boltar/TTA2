# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_policy(SET CMP0048 NEW)
project(TTA VERSION 1.0)

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

add_executable(TTA main.cpp Player.cpp Player.h GameEngine.cpp GameEngine.h)
add_subdirectory(tests)