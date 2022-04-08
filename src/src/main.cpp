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
    Heuristic* h = new Heuristic();
    g->board.draw();
    g->fromString("------------KQ-B-------------------------------------------------");
    g->board.draw();
    printf("%f\n", h->evaluateBoard(g->board, true));
    g->fromString("------------KQ-B----------------------------ppp---------P------P-");
    g->board.draw();
    printf("%f\n", h->evaluateBoard(g->board, true));
    g->fromString("------------KQ-B----------------------------ppp--------PP------P-");
    g->board.draw();
    printf("%f\n", h->evaluateBoard(g->board, true));
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}
