cmake_minimum_required(VERSION 3.15)

find_package(gRPC REQUIRED)

add_library(client_lib STATIC)
target_sources(client_lib PRIVATE src/client.cpp)
target_include_directories(client_lib PUBLIC include)
target_link_libraries(client_lib PUBLIC protocols)

add_executable(client_app src/main.cpp)
target_link_libraries(client_app PRIVATE client_lib)
target_link_libraries(client_app PUBLIC gRPC::grpc++ protobuf::libprotobuf)
