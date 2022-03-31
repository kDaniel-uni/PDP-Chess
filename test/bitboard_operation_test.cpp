//
// Pdp_chess university project
//

#include <string>
#include "board/bitboard_operations.h"
#include "game.h"
#include <iostream>

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    std::string arg = argv[1];
    Game game = Game();

    if (arg == "1"){

        game.fromString("--------pPpPpP--------pp---------------------P-p---PP-PP--------");
        uint64_t result = getWhitePawnsInBasePosition(game.board._pieces[white]->pawns);

        uint64_t expected_result = (1 << 9) + (1 << 11) + (1 << 13);

        if (result == expected_result){
            return EXIT_SUCCESS;
        }

    } else if (arg == "2"){

        game.fromString("--------pPpPpP--------pp---------------------P-p---pp-pp--------");
        uint64_t result = getBlackPawnsInBasePosition(game.board._pieces[black]->pawns);

        uint64_t base = 1;
        uint64_t expected_result = (base << 51) + (base << 52) + (base << 54) + (base << 55);

        if (result == expected_result){
            return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}