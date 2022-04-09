//
// Pdp_chess university project
//

#include "game.h"
#include "minmax_ab.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];

    if (arg == "1"){
        Heuristic heuristic = Heuristic();
        LegalMove legal_move = LegalMove();
        MinMaxAb* white_player = new MinMaxAb(heuristic, legal_move, 6);
        MinMaxAb* black_player = new MinMaxAb(heuristic, legal_move, 4);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        g.start();
    }
}