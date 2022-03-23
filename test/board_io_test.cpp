//
// Pdp_echec university project
//

#include "../include/bitboard_operations.h"
#include "iostream"

int main (int argc, char *argv[]) {

    std::string arg = argv[1];

    if (arg == "1"){

        Bitboards* bitboards = new Bitboards(true);
        std::string test_s = io_bitboard::to_string(bitboards);

        if (test_s == "----------------------------------------------------------------"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "2"){

        Bitboards* bitboards = new Bitboards(false);
        std::string test_s = io_bitboard::to_string(bitboards);

        if (test_s == "RNBKQBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "3"){

        Bitboards* bitboards =  io_bitboard::from_string("RNBKQBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
        std::string test_s = io_bitboard::to_string(bitboards);

        if (test_s == "RNBKQBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    } else if (arg == "4"){

        Bitboards* bitboards = io_bitboard::from_string("rnbkqb---nrpppp--pp------pp---KB--NR-----------P-P----PPPPPPRNBQ");
        std::string test_s = io_bitboard::to_string(bitboards);

        if (test_s == "rnbkqb---nrpppp--pp------pp---KB--NR-----------P-P----PPPPPPRNBQ"){
            return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}