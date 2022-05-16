cmake_minimum_required(VERSION 3.8)

project(working_places.out VERSION 2.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp read_write_data.cpp)

