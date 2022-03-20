cmake_minimum_required(VERSION 3.13)
project(pdp_echec)
include(CTest)

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

add_executable(placeholder_test src/tests/placeholder_test.cpp src/game.cpp src/board.cpp src/bitboard_operations.cpp)

target_include_directories(placeholder_test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

add_test(NAME placeholder
        COMMAND placeholder_test)
set_property(TEST placeholder APPEND PROPERTY LABELS TestLabel 0ArgTest Everything)