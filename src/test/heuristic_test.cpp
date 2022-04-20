//
// Pdp_chess university project
//

#include "engine/game.h"
#include "minmax_ab.h"
#include "heuristic.h"
#include "legal_move_v1.h"
#include <json/json.h>
#include <iostream>
#include <fstream>

using namespace pdp_chess;

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
        if(arg == "1"){
                g.fromString("------------K----------------------------------------------------");
                g.board.draw();
                printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true), h_doubled.evaluateBoard(g.board, true), h_backward.evaluateBoard(g.board, true), h_legal_move.evaluateBoard(g.board, true), h_bis.evaluateBoard(g.board, true));
        }
        if(arg == "2"){
                g.fromString("------------K-------------------------------------------P------P-");
                g.board.draw();
                printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true), h_doubled.evaluateBoard(g.board, true), h_backward.evaluateBoard(g.board, true), h_legal_move.evaluateBoard(g.board, true), h_bis.evaluateBoard(g.board, true));
        }
        if(arg == "3"){
                g.fromString("------------K-------------------p----------------------PP------P-");
                g.board.draw();
                printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true), h_doubled.evaluateBoard(g.board, true), h_backward.evaluateBoard(g.board, true), h_legal_move.evaluateBoard(g.board, true), h_bis.evaluateBoard(g.board, true));
                printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h.evaluateBoard(g.board, false), h_isolated.evaluateBoard(g.board, false), h_doubled.evaluateBoard(g.board, false), h_backward.evaluateBoard(g.board, false), h_legal_move.evaluateBoard(g.board, false), h_bis.evaluateBoard(g.board, false));
        }
        if(arg == "4"){
                g.fromString("------------K--------------------------p---------P-----PP------P-");
                g.board.draw();
                printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h.evaluateBoard(g.board, true), h_isolated.evaluateBoard(g.board, true), h_doubled.evaluateBoard(g.board, true), h_backward.evaluateBoard(g.board, true), h_legal_move.evaluateBoard(g.board, true), h_bis.evaluateBoard(g.board, true));
                printf("%d, isolated %d, doubled %d, backward %d, legal move %d, piece val %d\n", h.evaluateBoard(g.board, false), h_isolated.evaluateBoard(g.board, false), h_doubled.evaluateBoard(g.board, false), h_backward.evaluateBoard(g.board, false), h_legal_move.evaluateBoard(g.board, false), h_bis.evaluateBoard(g.board, false));

        }
}