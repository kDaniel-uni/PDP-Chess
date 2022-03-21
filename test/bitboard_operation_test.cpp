//
// Pdp_echec university project
//

#include "string"
#include "../include/bitboard_operations.h"

int main (int argc, char *argv[]) {

    std::string arg = argv[1];

    if (arg == "1"){

        Bitboards* testing_board = io_bitboard::from_string("--------pPpPpP--------pp---------------------P-p---PP-PP--------");
        Bitboard result = filters::get_white_pawns_in_base_position(testing_board->White_pawns);

        Bitboards* expexted_result = io_bitboard::from_string("---------------------------------------------------PP-PP--------");

        if (result == expexted_result->White_pawns){
            return EXIT_SUCCESS;
        }

    } else if (arg == "2"){

        Bitboards* testing_board = io_bitboard::from_string("--------pPpPpP--------pp----------------------Pp---PP-PP--------");
        Bitboard result = filters::get_black_pawns_in_base_position(testing_board->Black_pawns);

        Bitboards* expexted_result = io_bitboard::from_string("--------p-p-p---------------------------------------------------");

        if (result == expexted_result->Black_pawns){
            return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}