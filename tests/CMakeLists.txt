cmake_minimum_required(VERSION 3.15)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests test_client_server.cpp)
target_link_libraries(unit_tests PRIVATE gtest_main client_lib server_lib)
target_include_directories(unit_tests PRIVATE ../client/include ../server/include)

include(GoogleTest)
gtest_discover_tests(unit_tests)
