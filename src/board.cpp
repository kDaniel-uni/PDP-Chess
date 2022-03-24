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
    _pieces[0] = new Bitboards(true,false);
    _pieces[1] = new Bitboards(false,false);
}

void board::update_white_and_black_pieces(){
    for (int i = 0; i<2;i++){
        _pieces[i]->all = _pieces[i]->pawns | _pieces[i]->rooks | _pieces[i]->knights | _pieces[i]->bishops | _pieces[i]->queen | _pieces[i]->king;
    }
}

std::string board::to_string(){
    return io_bitboard::to_string(*_pieces);
}

void board::from_string(string data){
    *_pieces = io_bitboard::from_string(data.c_str());
    update_white_and_black_pieces();
}

bool board::is_game_over(){
    if(_pieces[0]->king == 0 || _pieces[1]->king == 0){
        return true;
    }
    return false;
}

std::string board::result(){
    if(_pieces[0]->king== 0){
        return "The winner is player black";
    }else if(_pieces[1]->king == 0){
        return "The winner is player White";
    }else{
        return "there is no winner";
    }
}