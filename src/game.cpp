//
// Created by KAAAAAAAAAAAAAAAAARL on 17/03/2022.
//

#include <iostream>
#include "game.h"

void game::drawBoard(std::string board) {
    int char_in_row = 0;
    for (char const &c: board) {
        if (char_in_row >= 8){
            std::cout << std::endl;
            char_in_row = 0;
        }
        std::cout << c << ' ';
        char_in_row ++;
    }
}
