//
// Pdp_echec university project
//

#include <iostream>
#include "../include/game.h"

game::game() {
    _board = new board();
}

void game::drawBoard() {
    io_bitboard::draw_board(*_board->_pieces);
}
