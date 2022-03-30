//
// Pdp_echec university project
//

#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "game.h"

int main (int argc, char *argv[]) {
    
    std::string arg = argv[1];
    game* g = new game();
    g->fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
    struct movement mv;

    if (arg == "1"){
        mv.start_position = 15;
        mv.target_position = 31;
        g->play_move(mv);
        if (g->_board->to_string() == "RNBQKBNRPPPPPPP----------------P----------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }
    }else if( arg == "2"){
        mv.start_position = 1;
        mv.target_position = 16;
        g->play_move(mv);
        if (g->_board->to_string() == "R-BQKBNRPPPPPPPPN-------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }
    }else if ( arg == "3"){
        g->fromString("---------------------------P------q-----------------------------");
        mv.start_position = 27;
        mv.target_position = 34;
        g->play_move(mv);
        if (g->_board->to_string() != "----------------------------------P-----------------------------"){
            return EXIT_FAILURE;
        }
        mv.start_position = 34;
        mv.target_position = 42;
        g->play_move(mv);
        if (g->_board->to_string() == "------------------------------------------P---------------------"){
            return EXIT_SUCCESS;
        }
    }else if ( arg == "4"){

        g->fromString("-----Q---------------------R-------------------------------q---r");
        mv.start_position = 27;
        mv.target_position = 59;
        g->play_move(mv);
        if (g->_board->to_string() != "-----Q-----------------------------------------------------R---r"){
            return EXIT_FAILURE;
        }
        mv.start_position = 63;
        mv.target_position = 59;
        g->play_move(mv);
        if (g->_board->to_string() != "-----Q-----------------------------------------------------r----"){
            return EXIT_FAILURE;
        }
        mv.start_position = 5;
        mv.target_position = 3;
        g->play_move(mv);
        if (g->_board->to_string() != "---Q-------------------------------------------------------r----"){
            return EXIT_FAILURE;
        }
        mv.start_position= 59;
        mv.target_position = 3;
        g->play_move(mv);
        if (g->_board->to_string() == "---r------------------------------------------------------------"){
            return EXIT_SUCCESS;
        }

    }
    return EXIT_FAILURE;

}