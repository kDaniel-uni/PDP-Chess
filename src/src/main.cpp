//
// Pdp_chess university project
//

#include <iostream>
#include <cstdlib>
#include "game.h"
#include "heuristic.h"

using namespace pdp_chess;

int main(int argc, char *argv[])
{
    Game* g = new Game();
    Heuristic* h = new Heuristic(1, 5, 3, 3, 9, 200);
    g->drawBoard();
    g->fromString("------------KQ-B-------------------------------------------------");
    g->drawBoard();
    printf("%d\n", g->board.getBoardValue(true, h));
    g->fromString("------------KQ-B----------------------------ppp------------------");
    g->drawBoard();
    printf("%d\n", g->board.getBoardValue(true, h));
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}
