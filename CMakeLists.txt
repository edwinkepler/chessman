cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_FLAGS "-std=c++14")

include_directories(./game)

add_library(chessman_game 
    ./game/pieces/piece.cpp 
    ./game/pieces/bishop.cpp 
    ./game/pieces/king.cpp
    ./game/pieces/knight.cpp
    ./game/pieces/pawn.cpp
    ./game/pieces/queen.cpp
    ./game/pieces/rook.cpp
    ./game/player/player.cpp
    ./game/board/board.cpp
    ./game/gamecontroller.cpp)

#Testing build
project(tests)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

add_executable(${PROJECT_NAME} ./game/tests/tests.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} chessman_game ${Boost_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${PROJECT_NAME})

#Game build, no tests
project(chessman-cli)

add_executable(${PROJECT_NAME} chessman-cli/chessman-cli.cpp)
target_link_libraries(${PROJECT_NAME} chessman_game)
