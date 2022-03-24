//
// Pdp_echec university project
//

#include "../include/game.h"
#include "iostream"

int main (int argc, char *argv[]) {

    std::string arg = argv[1];
    game* _game = new game();

    if (arg == "1"){

        _game->_board->reset_to_empty();
        std::string test_s = _game->_board->to_string();

        if (test_s == "----------------------------------------------------------------"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "2"){

        _game->_board->reset_to_classic();
        std::string test_s = _game->_board->to_string();

        if (test_s == "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "3"){

        _game->_board->from_string("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        std::string test_s = _game->_board->to_string();

        if (test_s == "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "4"){

        _game->_board->from_string("rnbkqb---nrpppp--pp------pp---KB--NR-----------P-P----PPPPPPRNBQ");
        std::string test_s = _game->_board->to_string();

        if (test_s == "rnbkqb---nrpppp--pp------pp---KB--NR-----------P-P----PPPPPPRNBQ"){
            return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}