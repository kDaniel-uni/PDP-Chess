cmake_minimum_required(VERSION 3.13)
project(pdp_echec)

enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_executable(pdp_echec
        src/main.cpp
        src/game.cpp
        src/board.cpp
        src/bitboard_operations.cpp)

target_include_directories(pdp_echec
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

add_executable(placeholder_test src/tests/placeholder_test.cpp)

add_test(NAME placeholder
        COMMAND placeholder_test)