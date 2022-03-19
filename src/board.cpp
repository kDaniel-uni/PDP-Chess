//
// Pdp_echec university project
//

#include <string>
#include <array>
#include "../include/board.h"
#include <iostream>
#include "../include/bitboard_operations.h"

using namespace std;

board::board(){
    _bitboards = new Bitboards(false);
}

void board::upgrade_white_and_black_pieces(){
    _bitboards->White_pieces = _bitboards->White_pawns | _bitboards->White_rooks | _bitboards->White_knights | _bitboards->White_bishops | _bitboards->White_queen | _bitboards->White_king;
    _bitboards->Black_pieces = _bitboards->Black_pawns | _bitboards->Black_rooks | _bitboards->Black_knights | _bitboards->Black_bishops | _bitboards->Black_queen | _bitboards->Black_king;
}

char* board::to_string(){
    return io_bitboard::to_string(_bitboards);
}

void board::from_string(string data){
    _bitboards = io_bitboard::from_string(data.c_str());
    upgrade_white_and_black_pieces();
}

bool board::is_game_over(){
    if(_bitboards->White_king == 0 || _bitboards->Black_king == 0){
        return true;
    }
    return false;
}

std::string board::result(){
    if(_bitboards->White_king == 0){
        return "The winner is player black";
    }else if(_bitboards->Black_king == 0){
        return "The winner is player White";
    }else{
        return "there is no winner";
    }
}