//
// Pdp_chess university project
//

#include <iostream>
#include <cstdlib>
#include "game.h"
#include "heuristic.h"
#include "minmax_ab.h"
#include "legal_move_v1.h"
#include "chrono"
#include <math.h>

using namespace pdp_chess;

int main(int argc, char *argv[])
{
    Game* g = new Game();
    LegalMoveV1 legal_move_v1 = LegalMoveV1();
    Heuristic h = Heuristic(legal_move_v1);

    MinMaxAb player = MinMaxAb(h, legal_move_v1, 3);
    //g->fromString("-------------------------Q-------------------------------------p");
    g->fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
    g->board.draw();

    g->board.doMove( player.askNextMove(g->board, white) );
    g->board.draw();
    g->board.doMove( player.askNextMove(g->board, black) );
    g->board.draw();

    g->board.doMove( player.askNextMove(g->board, white) );
    g->board.draw();
    g->board.doMove( player.askNextMove(g->board, black) );
    g->board.draw();

    /*printf("%f\n", h->evaluateBoard(g->board, true));
    g->fromString("------------KQ-B----------------------------ppp---------P------P-");
    g->board.draw();
    printf("%f\n", h->evaluateBoard(g->board, true));
    g->fromString("------------KQ-B----------------------------ppp--------PP------P-");
    g->board.draw();
    printf("%f\n", h->evaluateBoard(g->board, true));*/
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}
