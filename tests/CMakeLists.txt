cmake_minimum_required(VERSION 3.15)

# Set policies for modern CMake behavior
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Unset GTEST_ROOT to avoid conflicts
unset(GTEST_ROOT CACHE)

# Find GTest package with CONFIG mode
find_package(GTest REQUIRED CONFIG)

add_executable(unit_tests test_client_server.cpp)
target_link_libraries(unit_tests 
    PRIVATE 
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    client_lib 
    server_lib
)
target_include_directories(unit_tests 
    PRIVATE 
    ../client/include 
    ../server/include
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
