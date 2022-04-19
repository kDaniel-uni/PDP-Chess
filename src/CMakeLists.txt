cmake_minimum_required(VERSION 3.13)
project(pdp_chess)
include(CTest)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

find_package(jsoncpp REQUIRED)
get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)

message("FOUND CONFIG: ${jsoncpp_CONFIG}")
message("INCLUDE DIRS: ${JSON_INC_PATH}")
message("LIBRARIES: ${jsoncpp_lib}")

add_compile_options(-Ofast)

include_directories(include)
include_directories(include/algorithm)
include_directories(include/board)
include_directories(include/move)
include_directories(src/include/third_party)
include_directories(include/player)
include_directories(include/util)
include_directories(${JSON_INC_PATH})

include_directories(src)
include_directories(src/algorithm)
include_directories(src/move)
include_directories(src/board)
include_directories(src/player)

add_library(lib src/game.cpp
        src/board/board.cpp
        src/board/bitboard_operations.cpp
        src/move/legal_move.cpp
        src/move/legal_move_v2.cpp
        src/board/player_state.cpp
        src/algorithm/heuristic.cpp
        src/algorithm/minmax_ab.cpp
        src/algorithm/random_player.cpp
        src/util/vector_shuffle.cpp
        src/algorithm/ai_factory.cpp
        src/algorithm/negamax.cpp
        src/player/human_player.cpp)

target_link_libraries(lib jsoncpp_lib)

target_include_directories(lib
        PRIVATE
        include)


add_executable(pdp_chess src/main.cpp)
target_link_libraries(pdp_chess PUBLIC lib)

add_executable(board_io_test test/board_io_test.cpp)
target_link_libraries(board_io_test PUBLIC lib)

add_executable(bitboard_operation_test test/bitboard_operation_test.cpp)
target_link_libraries(bitboard_operation_test PUBLIC lib)

add_executable(bitboard_move_test test/bitboard_move_test.cpp)
target_link_libraries(bitboard_move_test PUBLIC lib)

add_executable(legal_move_test test/legal_move_test.cpp)
target_link_libraries(legal_move_test PUBLIC lib)

add_executable(game_test test/game_test.cpp)
target_link_libraries(game_test PUBLIC lib)

add_executable(heuristic_test test/heuristic_test.cpp)
target_link_libraries(heuristic_test PUBLIC lib)

add_executable(condition_isdraw_test test/condition_isdraw_test.cpp)
target_link_libraries(condition_isdraw_test PUBLIC lib)

add_executable(ai_factory_test test/ai_factory_test.cpp)
target_link_libraries(ai_factory_test PUBLIC lib)

add_executable(speed_test test/speed_test.cpp)
target_link_libraries(speed_test PUBLIC lib)

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
add_test(legal_move_v2_pawns_test legal_move_test 2)

add_test(legal_move_rooks_test legal_move_test 3)
add_test(legal_move_v2_rooks_test legal_move_test 4)

add_test(legal_move_bishops_test legal_move_test 5)
add_test(legal_move_v2_bishops_test legal_move_test 6)

add_test(legal_move_knights_test legal_move_test 7)
add_test(legal_move_v2_knights_test legal_move_test 8)

add_test(legal_move_queen_test legal_move_test 9)
add_test(legal_move_v2_queen_test legal_move_test 10)

add_test(legal_move_king_test legal_move_test 11)
add_test(legal_move_v2_king_test legal_move_test 12)

add_test(legal_move_basic_test legal_move_test 13)
add_test(legal_move_v2_basic_test legal_move_test 14)

add_test(speed_test_v1 legal_move_test 15)
add_test(speed_test_v2 legal_move_test 16)

add_test(heuristic_test_1 heuristic_test 1)
add_test(heuristic_test_2 heuristic_test 1)
add_test(heuristic_test_3 heuristic_test 1)
add_test(heuristic_test_4 heuristic_test 1)

add_test(draw_king_vs_king_test condition_isdraw_test 1)
add_test(draw_king_bishop_vs_king_test condition_isdraw_test 3)
add_test(draw_king_knight_vs_king_test condition_isdraw_test 4)
add_test(draw_king_bishop_vs_king_bishop_test condition_isdraw_test 5)
add_test(repetition_board_test condition_isdraw_test 2)

add_test(factory_test ai_factory_test 1)
