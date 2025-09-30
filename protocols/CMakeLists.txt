cmake_minimum_required(VERSION 3.15)

# This folder contains proto files and (for now) stub headers so the project can compile

add_library(protocols INTERFACE)
target_include_directories(protocols INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
