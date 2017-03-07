cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(TEST_FLOOR_FILES test_floor.cpp ../src/floor.cpp)
add_executable(TestFloor ${TEST_FLOOR_FILES})

target_link_libraries(TestFloor gtest gtest_main)