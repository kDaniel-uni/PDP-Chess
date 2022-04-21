//
// Pdp_chess university project
//

#include "engine/game.h"
#include "minmax_ab.h"
#include "valuation/heuristic.h"
#include "legal_move_v1.h"
#include <json/json.h>
#include <iostream>
#include <fstream>

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

int main (int argc, char *argv[]) {

        if (argc > 2) return EXIT_FAILURE;
        if (argc == 1) return EXIT_FAILURE;

        std::string arg = argv[1];
        LegalMoveV1 legal_move_v1 = LegalMoveV1();

        Heuristic h = Heuristic(legal_move_v1);

        HeuristicParameters heuristicParametersDoubled = HeuristicParameters();
        heuristicParametersDoubled.SetAllToZero();
        heuristicParametersDoubled.ChangeValue(pdp_chess::Doubled, 1);

        HeuristicParameters heuristicParametersIsolated = HeuristicParameters();
        heuristicParametersIsolated.SetAllToZero();
        heuristicParametersIsolated.ChangeValue(pdp_chess::Isolated, 1);

        HeuristicParameters heuristicParametersBackward = HeuristicParameters();
        heuristicParametersBackward.SetAllToZero();
        heuristicParametersBackward.ChangeValue(pdp_chess::Backward, 1);

        HeuristicParameters heuristicParametersLegal = HeuristicParameters();
        heuristicParametersLegal.SetAllToZero();
        heuristicParametersLegal.ChangeValue(pdp_chess::Legal, 1);

        HeuristicParameters heuristicParametersBis = HeuristicParameters();
        heuristicParametersBis.SetAllToZero();
        heuristicParametersBis.ChangeValue(pdp_chess::Pawns, 10);
        heuristicParametersBis.ChangeValue(pdp_chess::Rooks, 50);
        heuristicParametersBis.ChangeValue(pdp_chess::Bishops, 30);
        heuristicParametersBis.ChangeValue(pdp_chess::Knights, 30);
        heuristicParametersBis.ChangeValue(pdp_chess::Queen, 90);
        heuristicParametersBis.ChangeValue(pdp_chess::King, 2000);

        Heuristic h_doubled = Heuristic(legal_move_v1, heuristicParametersDoubled);
        Heuristic h_isolated = Heuristic(legal_move_v1, heuristicParametersIsolated);
        Heuristic h_backward = Heuristic(legal_move_v1, heuristicParametersBackward);
        Heuristic h_legal_move = Heuristic(legal_move_v1, heuristicParametersLegal);
        Heuristic h_bis = Heuristic(legal_move_v1, heuristicParametersBis);
        MinMaxAb* white_player = new MinMaxAb(h, legal_move_v1, 6);
        MinMaxAb* black_player = new MinMaxAb(h, legal_move_v1, 4);
        Game g = Game(white_player, black_player);
        int expected_result = 0;
        int result = 0;
        if(arg == "1"){
                g.fromString("------------K----------------------------------------------------");
                expected_result = 4016;
        }
        if(arg == "2"){
                g.fromString("------------K-------------------------------------------P------P-");
                expected_result = 4054;
        }
        if(arg == "3"){
                g.fromString("------------K-------------------p----------------------PP------P-");
                expected_result = 4064;
        }
        if(arg == "4"){
                g.fromString("------------K--------------------------p---------P-----PP------P-");
                expected_result = 4092;
        }
        //g.board.draw();
        //printEval(g.board, true, h, h_isolated, h_doubled, h_backward, h_legal_move, h_bis);
        //printEval(g.board, false, h, h_isolated, h_doubled, h_backward, h_legal_move, h_bis);
        result = h.evaluateBoard(g.board, true);
        if(expected_result == result)
                return EXIT_SUCCESS;
        return EXIT_FAILURE; 
}