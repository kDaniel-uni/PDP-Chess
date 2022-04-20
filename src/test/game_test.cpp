//
// Pdp_chess university project
//

#include "engine/game.h"
#include "minmax_ab.h"
#include "random_player.h"
#include "negamax.h"
#include "human_player.h"
#include "legal_move_v1.h"
#include "mcts.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];
    LegalMoveV1 legal_move_v1 = LegalMoveV1();

    if (arg == "1"){
        Heuristic heuristic = Heuristic(legal_move_v1);
        MinMaxAb* white_player = new MinMaxAb(heuristic, legal_move_v1, 5);
        MinMaxAb* black_player = new MinMaxAb(heuristic, legal_move_v1, 4);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        g.start();

    } else if (arg == "2"){
        Heuristic heuristic = Heuristic(legal_move_v1);
        RandomPlayer* white_player = new RandomPlayer(legal_move_v1);
        MinMaxAb* black_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        g.start();

    } else if (arg == "3"){
        Heuristic heuristic = Heuristic(legal_move_v1);
        Negamax* white_player = new Negamax(heuristic, legal_move_v1, 3);
        MinMaxAb* black_player = new MinMaxAb(heuristic, legal_move_v1, 3);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        g.start();

    } else if (arg == "4"){
        Heuristic heuristic = Heuristic(legal_move_v1);
        HumanPlayer* white_player = new HumanPlayer(legal_move_v1);
        MinMaxAb* black_player = new MinMaxAb(heuristic, legal_move_v1, 2);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        g.start();
    }
    else if(arg=="3"){
        Heuristic heuristic = Heuristic(legal_move_v1);
        MCTS* white_player = new MCTS(heuristic, legal_move_v1, 2, 10);
        MCTS* black_player = new MCTS(heuristic, legal_move_v1, 3, 10);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        g.start();







    }
}