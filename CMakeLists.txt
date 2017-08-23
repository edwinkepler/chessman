cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_FLAGS "-std=c++14")

#Game build, no tests
project(chessman-cli)

add_executable(${PROJECT_NAME} chessman-cli/chessman-cli.cpp)
