cmake_minimum_required(VERSION 3.15)
project(grpc_cpp_demo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TESTS "Build unit tests" ON)

add_subdirectory(protocols)
add_subdirectory(server)
add_subdirectory(client)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
