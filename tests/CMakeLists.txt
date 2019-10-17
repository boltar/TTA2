# 'Google_test' is the subproject name
project(tests)
find_package(Boost 1.71.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message("BOOST found")
else()
    message("ERROR: boost not found")
endif()
# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(lib/googletest/include lib/googletest)
# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(tests TestPlayer.cpp TestGameEngine.cpp ../Player.cpp ../Player.hpp ../GameEngine.cpp ../GameEngine.hpp ../Building.cpp ../Building.hpp ../Constants.hpp ../Match.cpp ../Match.hpp TestMatch.cpp)
target_link_libraries(tests gtest gtest_main)
