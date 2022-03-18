//
// Pdp_echec university project
//

#include <iostream>
#include "../include/game.h"

game::game() {
    _board = new board();
}

void game::drawBoard() {
    char* chars = _board->to_string();
    int char_in_row = 0;
    for (int index = 0; index < BOARD_SIZE; index++) {
        if (char_in_row >= 8){
            std::cout << std::endl;
            char_in_row = 0;
        }
        std::cout << chars[index] << ' ';
        char_in_row ++;
    }
    std::cout << std::endl << std::endl;
}
