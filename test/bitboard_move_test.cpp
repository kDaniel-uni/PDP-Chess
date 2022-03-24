//
// Pdp_echec university project
//

#include <string.h>
#include "../include/bitboard_operations.h"
#include "../include/move.h"

int main (int argc, char *argv[]) {


  
    struct move move_to_test;
    move_to_test.moving_position = "h2";
    move_to_test.target_position = "h4";
    Bitboards* bitboards = new Bitboards(false);
    bitboards = io_bitboard::traduct_from_move(bitboards,move_to_test);
    if (io_bitboard::to_string(bitboards)== "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}