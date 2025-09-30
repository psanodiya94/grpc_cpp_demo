cmake_minimum_required(VERSION 3.15)

add_library(server_lib STATIC)
target_sources(server_lib PRIVATE src/server.cpp)
target_include_directories(server_lib PUBLIC include)
target_link_libraries(server_lib PUBLIC protocols)

add_executable(server_app src/main.cpp)
target_link_libraries(server_app PRIVATE server_lib)
