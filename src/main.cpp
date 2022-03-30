//
// Pdp_echec university project
//

#include <iostream>
#include <cstdlib>
#include "game.h"
#include "heuristic.h"

int main(int argc, char *argv[])
{
    game* g = new game();
    heuristic* h = new heuristic(1, 5, 3, 3, 9, 200);
    g->drawBoard();
    g->fromString("------------KQ-B-------------------------------------------------");
    g->drawBoard();
    printf("%d\n", g->_board->get_board_value(true, h));
    g->fromString("------------KQ-B----------------------------ppp------------------");
    g->drawBoard();
    printf("%d\n", g->_board->get_board_value(true, h));
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}
