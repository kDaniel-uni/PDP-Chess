//
// Pdp_chess university project
//

#include "engine/game.h"
#include "iostream"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];
    Game game = Game();

    if (arg == "1"){

        game.board.resetToEmpty();
        std::string test_s = game.board.toString();
        game.draw();

        if (test_s == "----------------------------------------------------------------"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "2"){

        game.board.resetToClassic();
        std::string test_s = game.board.toString();
        game.draw();
        if (test_s == "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "3"){

        game.board.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        std::string test_s = game.board.toString();
        game.draw();
        if (test_s == "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "4"){

        game.board.fromString("rnbkqb---nrpppp--pp------pp---KB--NR-----------P-P----PPPPPPRNBQ");
        std::string test_s = game.board.toString();
        game.draw();
        if (test_s == "rnbkqb---nrpppp--pp------pp---KB--NR-----------P-P----PPPPPPRNBQ"){
            return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}