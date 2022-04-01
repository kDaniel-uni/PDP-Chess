//
// Pdp_chess university project
//

#include <iostream>
#include "game.h"

namespace pdp_chess {

    Game::Game() {
        board = Board();
        _current_color = white;
    }

    void Game::fromString(std::string string) {
        board.fromString(string.c_str());
    }

    void Game::drawBoard() const{
        std::string chars = board.toString();

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

    /*void Game::step(){
        _players[_current_color]->findNextMove();
    }*/

    void Game::playMove(Move move){
        board.doMove(move);
        _current_color = (color)!_current_color;
    }

    bool Game::getPlayerRound(){
        bool white = false;
        //Move move = _history.back();
        //return (bool)!board.getColor(move.target_position);
        return true;
    }

}