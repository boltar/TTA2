# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_policy(SET CMP0048 NEW)
project(TTA VERSION 1.0)

find_package(Boost 1.71.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(BOOST_ROOT "../boost/boost_1_71_0")

find_package(Boost 1.71.0)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

add_executable(TTA main.cpp Player.cpp Player.hpp GameEngine.cpp GameEngine.hpp Building.cpp Building.hpp Constants.hpp Match.cpp Match.hpp CivilDeck.cpp CivilDeck.hpp Card.cpp Card.hpp GameDeck.cpp GameDeck.hpp CardRow.cpp CardRow.hpp)
add_subdirectory(tests)