cmake_minimum_required(VERSION 3.13)
project(pdp_echec)
include(CTest)
set(CMAKE_CXX_STANDARD 14)
enable_testing()

add_library(lib src/game.cpp
        src/board.cpp
        src/bitboard_operations.cpp)

target_include_directories(lib
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)


add_executable(pdp_echec src/main.cpp)
target_link_libraries(pdp_echec PUBLIC lib)

add_executable(placeholder_test test/placeholder_test.cpp)
target_link_libraries(placeholder_test PUBLIC lib)

add_executable(bitboard_io_test test/bitboard_io_test.cpp)
target_link_libraries(bitboard_io_test PUBLIC lib)


add_test(placeholder placeholder_test)

add_test(board_empty_init_test bitboard_io_test 1)
add_test(board_classic_init_test bitboard_io_test 2)
add_test(bitboard_basic_load_test bitboard_io_test 3)
add_test(bitboard_random_load_test bitboard_io_test 4)