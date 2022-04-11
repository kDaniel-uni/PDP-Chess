//
// Pdp_chess university project
//

#include "game.h"
#include "minmax_ab.h"
#include "heuristic.h"

using namespace pdp_chess;

void printEval(Board b, bool color, Heuristic h, Heuristic h_isolated, Heuristic h_doubled, 
Heuristic h_backward, Heuristic h_legal_move, Heuristic h_piece){
        int h_eval = h.evaluateBoard(b, color);
        int h_i = h_isolated.evaluateBoard(b, color);
        int h_d = h_doubled.evaluateBoard(b, color);
        int h_b = h_backward.evaluateBoard(b, color);
        int h_l_m = h_legal_move.evaluateBoard(b, color);
        int h_p = h_piece.evaluateBoard(b, color);
        printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h_eval, h_i, h_d, h_b, h_l_m, h_p);
}

void printEvalPawnForward(Board b, bool color, Heuristic h_p_f){
        int h_pawn_forward = h_p_f.evaluateBoard(b, color);
        printf("pawn forward %d\n", h_pawn_forward);
}

int main (int argc, char *argv[]) {

        if (argc > 2) return EXIT_FAILURE;
        if (argc == 1) return EXIT_FAILURE;

        std::string arg = argv[1];

        Heuristic h = Heuristic();
        Heuristic h_doubled = Heuristic(0,0,0,0,0,0,0,0,10,0,0);
        Heuristic h_isolated = Heuristic(0,0,0,0,0,0,0,10,0,0,0);
        Heuristic h_backward = Heuristic(0,0,0,0,0,0,10,0,0,0,0);
        Heuristic h_legal_move = Heuristic(0,0,0,0,0,0,0,0,0,2,0);
        Heuristic h_piece = Heuristic(20, 100, 60, 60, 180, 4000, 0, 0, 0, 0,0);
        Heuristic h_pawn_forward = Heuristic(0, 0, 0, 0, 0, 0, 0, 0, 0, 0,1);
        LegalMove legal_move = LegalMove();
        MinMaxAb* white_player = new MinMaxAb(h, legal_move, 6);
        MinMaxAb* black_player = new MinMaxAb(h, legal_move, 4);
        Game g = Game(white_player, black_player);
        int expected_result = 0;
        int result = 0;
        if(arg == "1"){
                g.fromString("------------K----------------------------------------------------");
                g.board.draw();
                printEval(g.board, true, h, h_isolated, h_doubled, h_backward, h_legal_move, h_piece);
                printEvalPawnForward(g.board, true, h_pawn_forward);
                result = h.evaluateBoard(g.board, true);
                expected_result = 4016;
        }
        if(arg == "2"){
                g.fromString("------------K-------------------------------------------P------P-");
                g.board.draw();
                printEval(g.board, true, h, h_isolated, h_doubled, h_backward, h_legal_move, h_piece);
                printEvalPawnForward(g.board, true, h_pawn_forward);
                result = h.evaluateBoard(g.board, true);
                expected_result = 4054;
        }
        if(arg == "3"){
                g.fromString("------------K-------------------p----------------------PP------P-");
                g.board.draw();
                printEval(g.board, true, h, h_isolated, h_doubled, h_backward, h_legal_move, h_piece);
                printEvalPawnForward(g.board, true, h_pawn_forward);
                result = h.evaluateBoard(g.board, true);
                expected_result = 4064;
        }
        if(arg == "4"){
                g.fromString("------------K--------------------------p---------P-----PP------P-");
                g.board.draw();
                printEval(g.board, true, h, h_isolated, h_doubled, h_backward, h_legal_move, h_piece);
                printEval(g.board, false, h, h_isolated, h_doubled, h_backward, h_legal_move, h_piece);
                printEvalPawnForward(g.board, true, h_pawn_forward);
                result = h.evaluateBoard(g.board, true);
                expected_result = 4092;
        }
        if(expected_result == result)
                return EXIT_SUCCESS;
        return EXIT_FAILURE; 
}