//
// Pdp_chess university project
//

#include "game.h"
#include "minmax_ab.h"
#include "heuristic.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

        Heuristic h = Heuristic();
        Heuristic h_doubled = Heuristic(0,0,0,0,0,0,0,0,1);
        Heuristic h_isolated = Heuristic(0,0,0,0,0,0,0,1,0);
        Heuristic h_backward = Heuristic(0,0,0,0,0,0,1,0,0);
        LegalMove legal_move = LegalMove();
        MinMaxAb* white_player = new MinMaxAb(h, legal_move, 6);
        MinMaxAb* black_player = new MinMaxAb(h, legal_move, 4);
        Game g = Game(white_player, black_player);
        g.fromString("------------K----------------------------------------------------");
        g.board.draw();
        printf("%d\n", h.evaluateBoard(g.board, true));
        g.fromString("------------K-------------------------------------------P------P-");
        g.board.draw();
        printf("%d, isolated %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true));
        g.fromString("------------K------------------------------------------PP------P-");
        g.board.draw();
        printf("%d, isolated %d, doubled %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true), h_doubled.evaluateBoard(g.board, true));
        g.fromString("------------K--------------------------p---------P-----PP------P-");
        g.board.draw();
        printf("%d, isolated %d, doubled %d, backward %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true), h_doubled.evaluateBoard(g.board, true), h_backward.evaluateBoard(g.board, true));
}