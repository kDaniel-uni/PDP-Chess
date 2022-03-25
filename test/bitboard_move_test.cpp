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
    }
    return EXIT_FAILURE;

}