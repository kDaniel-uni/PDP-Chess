//
// Pdp_chess university project
//

#include <string>
#include "bitboard_operations.h"
#include "engine/game.h"
#include <chrono>
#include <iostream>

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

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

    } else if (arg == "3"){

        game.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            //std::vector<uint8_t> result = getPositions(game.board._pieces[white]->pawns);
            std::vector<uint8_t> result = getPositionsV1(game.board._pieces[white]->king.value);

            //std::vector<uint8_t> expected_result = {8,9,10,11,12,13,14,15};
            std::vector<uint8_t> expected_result = {4};

            if (result != expected_result){
                return EXIT_FAILURE;
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;

    }else if (arg == "4"){

        game.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            //std::vector<uint8_t> result = getPositionsV1(game.board._pieces[white]->pawns.value);
            std::vector<uint8_t> result = getPositionsV1(game.board._pieces[white]->king.value);

            //std::vector<uint8_t> expected_result = {8,9,10,11,12,13,14,15};
            std::vector<uint8_t> expected_result = {4};

            if (result != expected_result){
                return EXIT_FAILURE;
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}