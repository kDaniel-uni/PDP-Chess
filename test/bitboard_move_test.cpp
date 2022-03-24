//
// Pdp_echec university project
//

#include <string.h>
#include "../include/bitboard_operations.h"
#include "../include/move.h"
#include "../include/game.h"

int main (int argc, char *argv[]) {


    struct movement mv;
    mv.start_position = 15;
    mv.target_position = 31;
    game* g = new game();
    g->_board->moving(mv);
    if (g->_board->to_string() == "RNBQKBNRPPPPPPP----------------P----------------pppppppprnbqkbnr"){
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}