//
// Pdp_echec university project
//

#include <iostream>
#include <cstdlib>
#include "../include/game.h"

int main(int argc, char *argv[])
{
    game* g = new game();
    g->drawBoard();
    g->_board->from_string("------------KQ-B-------------------------------------------------");
    g->drawBoard();
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}