//
// Pdp_echec university project
//

#include <iostream>
#include "game.h"

game::game() {
    _board = new board();
}

void game::fromString(std::string string) {
    _board->from_string(string.c_str());
}

void game::drawBoard() const{
    std::string chars = _board->to_string();

    std::cout << std::endl << "    a b c d e f g h" << std::endl << "   -----------------" << std::endl;
    for (int current_y = 7; current_y >= 0; current_y--){
        std::cout << current_y + 1 << " | ";
        for (int current_x = 0; current_x < 8; current_x++){
            std::cout << chars[current_y * 8 + current_x] << ' ';
        }
        std::cout << "| " << current_y + 1<< std::endl;
    }

    std::cout << "   -----------------" << std::endl << "    a b c d e f g h" << std::endl  << std::endl;
}

void game::play_move(movement move){
    this->_history.push_back(move);
    _board->moving(move);
}

bool game::get_player_round(){
    bool white = false;
    movement move = _history.back();
    return (bool)!_board->get_color(move.target_position);
}
