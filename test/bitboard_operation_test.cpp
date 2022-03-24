//
// Pdp_echec university project
//

#include <string>
#include "bitboard_operations.h"
#include "game.h"
#include <iostream>

int main (int argc, char *argv[]) {

    std::string arg = argv[1];
    game* _game = new game();

    if (arg == "1"){

        _game->fromString("--------pPpPpP--------pp---------------------P-p---PP-PP--------");
        uint64_t result = filters::get_white_pawns_in_base_position(_game->_board->_pieces[1]->pawns);

        uint64_t expected_result = (1 << 9) + (1 << 11) + (1 << 13);

        if (result == expected_result){
            return EXIT_SUCCESS;
        }

    } else if (arg == "2"){

        _game->fromString("--------pPpPpP--------pp---------------------P-p---pp-pp--------");
        uint64_t result = filters::get_black_pawns_in_base_position(_game->_board->_pieces[0]->pawns);

        uint64_t base = 1;
        uint64_t expected_result = (base << 51) + (base << 52) + (base << 54) + (base << 55);

        if (result == expected_result){
            return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}