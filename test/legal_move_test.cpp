#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "game.h"
#include "legal_move.h"

int main (int argc, char *argv[]) {
    std::string arg = argv[1];
    game* g = new game();
    g->_board->from_string("--------P--------p----------------------------------------------");
    std::vector<movement> to_test = pdp_chess::legal_move_pawns(*g->_board,true);
    for(movement m : to_test){
        if((int)m.start_position != 8 ){
            return EXIT_FAILURE;
        }
        else{
            if(((int)m.target_position != 24) && ((int)m.target_position != 16) && ((int)m.target_position != 17) ){
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;




}