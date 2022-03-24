cmake_minimum_required(VERSION 3.13)
project(pdp_echec)
include(CTest)
set(CMAKE_CXX_STANDARD 14)
enable_testing()

include_directories(src/include)

add_library(lib src/game.cpp
        src/board.cpp
        src/bitboard_operations.cpp)

target_include_directories(lib
        PRIVATE
        src/include)


add_executable(pdp_echec src/main.cpp)
target_link_libraries(pdp_echec PUBLIC lib)

add_executable(placeholder_test test/placeholder_test.cpp)
target_link_libraries(placeholder_test PUBLIC lib)

add_executable(board_io_test test/board_io_test.cpp)
target_link_libraries(board_io_test PUBLIC lib)

add_executable(bitboard_operation_test test/bitboard_operation_test.cpp)
target_link_libraries(bitboard_operation_test PUBLIC lib)


add_test(placeholder placeholder_test)

add_test(board_empty_init_test board_io_test 1)
add_test(board_classic_init_test board_io_test 2)
add_test(board_basic_load_test board_io_test 3)
add_test(board_random_load_test board_io_test 4)

add_test(white_pawns_in_base_pos_test bitboard_operation_test 1)
add_test(black_pawns_in_base_pos_test bitboard_operation_test 2)