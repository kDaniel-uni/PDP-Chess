//
// Pdp_echec university project
//

#include <string>
#include <array>
#include <iostream>
#include <math.h>
#include "../include/board.h"
#include "bitboard_operations.h"

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