//
// Pdp_echec university project
//

#include <string>
#include <array>
#include <iostream>
#include <math.h>
#include "board/board.h"
#include "board/bitboard_operations.h"
#include "algorithm/heuristic.h"

using namespace std;

board::board() {
    _pieces[0] = new Bitboards(false, true);
    _pieces[1] = new Bitboards(true, true);
}

void board::update_white_and_black_pieces() {
    for (int i = 0; i < 2; i++) {
        for (auto bitboard : _pieces[i]->list){
            _pieces[i]->all.value += bitboard->value;
        }
    }
}

int board::get_board_value(bool white_black_turn, heuristic* h){
    int  value = _pieces[1]->get_bitboard_value(h) - _pieces[0]->get_bitboard_value(h);
    if(white_black_turn)
        return value;
    else
        return -1*value;
}

std::string board::to_string() {
    std::string res;
    res.resize(64);

    for (int index = 0; index < BOARD_SIZE; index++) {
        res[index] = '-';
    }

    for (short color = 0; color < 2; color++) {
        for (Bitboard *bitboard : _pieces[color]->list) {
            for (auto index : io_bitboard::get_positions(*bitboard)) {
                res[index] = bitboard->type;
            }
        }
    }

    return res;
}

void board::from_string(const char *data) {

    reset_to_empty();

    for (auto index = 0; index < BOARD_SIZE; index++) {
        switch (data[index]) {
            case 'P':
                _pieces[1]->pawns.value += pow(2, index);
                break;
            case 'p':
                _pieces[0]->pawns.value += pow(2, index);
                break;
            case 'R':
                _pieces[1]->rooks.value += pow(2, index);
                break;
            case 'r':
                _pieces[0]->rooks.value += pow(2, index);
                break;
            case 'N':
                _pieces[1]->knights.value += pow(2, index);
                break;
            case 'n':
                _pieces[0]->knights.value += pow(2, index);
                break;
            case 'B':
                _pieces[1]->bishops.value += pow(2, index);
                break;
            case 'b':
                _pieces[0]->bishops.value += pow(2, index);
                break;
            case 'Q':
                _pieces[1]->queen.value += pow(2, index);
                break;
            case 'q':
                _pieces[0]->queen.value += pow(2, index);
                break;
            case 'K':
                _pieces[1]->king.value += pow(2, index);
                break;
            case 'k':
                _pieces[0]->king.value += pow(2, index);
                break;
            default:
                break;
        }
    }
    update_white_and_black_pieces();
}
void  board::moving(movement mv){
        uint64_t base= 1;
        uint64_t mask = (base<<mv.start_position)+(base<<mv.target_position);
        if ((_pieces[0]->all.value >> mv.target_position) & 1) {
            io_bitboard::eat_piece(mv.target_position, *_pieces[0]);
        }
        if ((_pieces[1]->all.value >> mv.target_position) & 1){
            io_bitboard::eat_piece(mv.target_position, *_pieces[1]);
        }
        for(int color = 0; color<2 ; color++ ){
            for(auto index : io_bitboard::get_positions(_pieces[color]->pawns)){
                if (index == mv.start_position){
                    io_bitboard::move_piece(mask,_pieces[color]->pawns);
                }
            }
            for(auto index : io_bitboard::get_positions(_pieces[color]->rooks)){
                if (index == mv.start_position){
                    io_bitboard::move_piece(mask,_pieces[color]->rooks);
                }
            }
            for(auto index : io_bitboard::get_positions(_pieces[color]->knights)){
                if (index == mv.start_position){
                   io_bitboard::move_piece(mask,_pieces[color]->knights);
                }
            }
            for(auto index : io_bitboard::get_positions(_pieces[color]->bishops)){
                if (index == mv.start_position){
                    io_bitboard::move_piece(mask,_pieces[color]->bishops);
                }
            }
            for(auto index : io_bitboard::get_positions(_pieces[color]->queen)){
                if (index == mv.start_position){
                    io_bitboard::move_piece(mask,_pieces[color]->queen);
                }
            }
            for(auto index : io_bitboard::get_positions(_pieces[color]->king)){
                if (index == mv.start_position){
                    io_bitboard::move_piece(mask,_pieces[color]->king);
                }
            }
            update_white_and_black_pieces();

            
        }
    }

bool board::is_game_over() {
    if (_pieces[0]->king.value == 0 || _pieces[1]->king.value == 0) {
        return true;
    }
    return false;
}

std::string board::result() {
    if (_pieces[0]->king.value == 0) {
        return "The winner is player black";
    } else if (_pieces[1]->king.value == 0) {
        return "The winner is player White";
    } else {
        return "there is no winner";
    }
}

void board::reset_to_classic() {
    _pieces[0] = new Bitboards(false, false);
    _pieces[1] = new Bitboards(true, false);
}

void board::reset_to_empty() {
    _pieces[0] = new Bitboards(false, true);
    _pieces[1] = new Bitboards(true, true);
}

int board::get_color(int index){
    for (int color = 0 ; color < 2; color++){
        if ((_pieces[color]->all.value >> index)&1){
            return color;
        }
    }
    return -1;
}