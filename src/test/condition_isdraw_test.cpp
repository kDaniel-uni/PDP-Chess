//
// Pdp_chess university project
//

#include "engine/game.h"
#include "minmax_ab.h"
#include "legal_move_v1.h"
#include <cstring>

using namespace pdp_chess;

int main(int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];
    LegalMoveV1 legal_move_v1 = LegalMoveV1();
    Heuristic heuristic = Heuristic(legal_move_v1);


    if (arg == "1") {
        MinMaxAb *white_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        MinMaxAb *black_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        Game g = Game(white_player, black_player);
        g.fromString("----------------K---------------------------k-------------------");
        g.start();
        if (strcmp(g.board.result().c_str(), "No winner") == 0) {
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    } else if (arg == "2") {
        Game g = Game();
        g.board.resetToClassic();
        Move mv1;
        mv1.start_position = 1;
        mv1.start_type = 'N';
        mv1.target_position = 18;
        Move mv2;
        mv2.start_position = 57;
        mv2.start_type = 'n';
        mv2.target_position = 42;
        Move mv3;
        mv3.start_position = 18;
        mv3.start_type = 'N';
        mv3.target_position = 1;
        Move mv4;
        mv4.start_position = 42;
        mv4.start_type = 'n';
        mv4.target_position = 57;
        g.board.doMove(mv1);
        g.board.doMove(mv2);
        g.board.doMove(mv3);
        g.board.doMove(mv4);
        g.board.doMove(mv1);
        g.board.doMove(mv2);
        g.board.doMove(mv3);
        g.board.doMove(mv4);
        if (g.board.isGameOver() && (strcmp(g.board.result().c_str(), "No winner") == 0)) {
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;

    } else if (arg == "3") {
        MinMaxAb *white_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        MinMaxAb *black_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        Game g = Game(white_player, black_player);
        g.fromString("----------------KB--------------------------k-------------------");
        g.start();
        if (strcmp(g.board.result().c_str(), "No winner") != 0) {
            return EXIT_FAILURE;
        }
        g.fromString("----------------K---------------------------kb------------------");
        g.start();
        if (strcmp(g.board.result().c_str(), "No winner") != 0) {
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;

    } else if (arg == "4") {
        MinMaxAb *white_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        MinMaxAb *black_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        Game g = Game(white_player, black_player);
        g.fromString("----------------KN--------------------------k-------------------");
        g.start();
        if (strcmp(g.board.result().c_str(), "No winner") != 0) {
            return EXIT_FAILURE;
        }
        g.fromString("----------------K---------------------------kn------------------");
        g.start();
        if (strcmp(g.board.result().c_str(), "No winner") != 0) {
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;

    } else if (arg == "5") {
        MinMaxAb *white_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        MinMaxAb *black_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        Game g = Game(white_player, black_player);
        g.fromString("----------------KB--------------------------kb------------------");
        g.start();
        if (strcmp(g.board.result().c_str(), "No winner") == 0) {
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    }

}