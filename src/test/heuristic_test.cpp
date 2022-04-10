//
// Pdp_chess university project
//

#include "game.h"
#include "minmax_ab.h"
#include "heuristic.h"
#include <json/json.h>
#include <iostream>
#include <fstream>

using namespace pdp_chess;

int main (int argc, char *argv[]) {

        if (argc > 2) return EXIT_FAILURE;
        if (argc == 1) return EXIT_FAILURE;

        std::string arg = argv[1];

        Heuristic h = Heuristic();
        Heuristic h_doubled = Heuristic(0,0,0,0,0,0,0,0,1,0);
        Heuristic h_isolated = Heuristic(0,0,0,0,0,0,0,1,0,0);
        Heuristic h_backward = Heuristic(0,0,0,0,0,0,1,0,0,0);
        Heuristic h_legal_move = Heuristic(0,0,0,0,0,0,0,0,0,1);
        Heuristic h_bis = Heuristic(10, 50, 30, 30, 90, 2000, 0, 0, 0, 0);
        LegalMove legal_move = LegalMove();
        MinMaxAb* white_player = new MinMaxAb(h, legal_move, 6);
        MinMaxAb* black_player = new MinMaxAb(h, legal_move, 4);
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

        } else if (arg == "5") {
            std::ifstream input_stream("../json_exemple/heuristic_test.json");
            Json::Reader reader;
            Json::Value json_object;
            reader.parse(input_stream, json_object);
            Heuristic json_heuristic = Heuristic(json_object["Heuristic"]);
            LegalMove legal_move1 = LegalMove();
            MinMaxAb* white_player1 = new MinMaxAb(json_heuristic, legal_move, 5);
            MinMaxAb* black_player1 = new MinMaxAb(json_heuristic, legal_move, 3);
            Game g1 = Game(white_player1, black_player1);
            g1.loadBasicBoard();
            g1.start();
        }
}