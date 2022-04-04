cmake_minimum_required(VERSION 3.13)
project(pdp_chess)
include(CTest)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

add_compile_options(-Ofast)

include_directories(src/include)
include_directories(src/include/algorithm)
include_directories(src/include/board)
include_directories(src/include/move)
include_directories(src/include/third_party)

include_directories(src/src)
include_directories(src/src/algorithm)
include_directories(src/src/move)
include_directories(src/src/board)

add_library(lib src/src/game.cpp
        src/src/board/board.cpp
        src/src/board/bitboard_operations.cpp
        src/src/move/legal_move.cpp
        src/src/move/legal_move_v2.cpp
        src/src/board/bitboards.cpp
        src/src/algorithm/heuristic.cpp test/legal_move_v2_test.cpp)

target_include_directories(lib
        PRIVATE
        src/include)


add_executable(pdp_chess src/src/main.cpp)
target_link_libraries(pdp_chess PUBLIC lib)

add_executable(board_io_test test/board_io_test.cpp)
target_link_libraries(board_io_test PUBLIC lib)

add_executable(bitboard_operation_test test/bitboard_operation_test.cpp)
target_link_libraries(bitboard_operation_test PUBLIC lib)

add_executable(bitboard_move_test test/bitboard_move_test.cpp)
target_link_libraries(bitboard_move_test PUBLIC lib)

add_executable(legal_move_test test/legal_move_test.cpp)
target_link_libraries(legal_move_test PUBLIC lib)

add_executable(legal_move_v2_test test/legal_move_v2_test.cpp)
target_link_libraries(legal_move_v2_test PUBLIC lib)


add_test(board_empty_init_test board_io_test 1)
add_test(board_classic_init_test board_io_test 2)
add_test(board_basic_load_test board_io_test 3)
add_test(board_random_load_test board_io_test 4)

add_test(white_pawns_in_base_pos_test bitboard_operation_test 1)
add_test(black_pawns_in_base_pos_test bitboard_operation_test 2)
add_test(get_positions_test bitboard_operation_test 3)
add_test(get_positions_v2_test bitboard_operation_test 4)

add_test(move_pawns_test bitboard_move_test 1)
add_test(move_knight_test bitboard_move_test 2)
add_test(move_eat_test bitboard_move_test 3)
add_test(move_chain_eat_test bitboard_move_test 4)
add_test(move_undo_redo_test bitboard_move_test 5)

add_test(legal_move_pawns_test legal_move_test 1)
add_test(legal_move_v2_pawns_test legal_move_v2_test 1)

add_test(legal_move_rooks_test legal_move_test 2)
add_test(legal_move_v2_rooks_test legal_move_v2_test 2)

add_test(legal_move_bishops_test legal_move_test 3)
add_test(legal_move_v2_bishops_test legal_move_v2_test 3)

add_test(legal_move_knights_test legal_move_test 4)
add_test(legal_move_v2_knights_test legal_move_v2_test 4)

add_test(legal_move_queen_test legal_move_test 5)
add_test(legal_move_v2_queen_test legal_move_v2_test 5)

add_test(legal_move_king_test legal_move_test 6)
add_test(legal_move_v2_king_test legal_move_v2_test 6)

