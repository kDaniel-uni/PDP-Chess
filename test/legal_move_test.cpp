//
// Pdp_chess university project
//

#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "game.h"
#include "legal_move.h"
#include <iostream>
#include <chrono>

using namespace pdp_chess;

int main (int argc, char *argv[]) {
    std::string arg = argv[1];
    Game g = Game();
    std::vector<Move> to_test;

    if (arg == "1"){
        g.board.fromString("--------P--------p----------------------------------------------");
        g.drawBoard();

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            to_test = pdp_chess::legal_move(g.board,true);

            if (to_test.size() != 3){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if((int)m.start_position != 8 ){
                    return EXIT_FAILURE;
                }
                else{
                    if(((int)m.target_position != 24) && ((int)m.target_position != 16) && ((int)m.target_position != 17) ){
                        return EXIT_FAILURE;
                    }
                }
            }

            to_test = pdp_chess::legal_move(g.board,false);

            if (to_test.size() != 2){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if((int)m.start_position != 17 ){
                    return EXIT_FAILURE;
                }
                else{
                    if( ((int)m.target_position != 9) && ((int)m.target_position != 8) ){
                        return EXIT_FAILURE;
                    }
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;

    }else if( arg == "2"){
        g.board.fromString("R---------------r-----------------------------------------------");
        g.drawBoard();

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            to_test = pdp_chess::legal_move(g.board,true);

            if (to_test.size() != 9){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if((int)m.start_position != 0 ){
                    return EXIT_FAILURE;
                }else if( ((int)m.target_position != 8) && ((int)m.target_position != 16) && ((int)m.target_position != 1) && ((int)m.target_position != 2) && ((int)m.target_position != 3) && ((int)m.target_position != 4) && ((int)m.target_position != 5) && ((int)m.target_position != 6) && ((int)m.target_position != 7) ){
                    return EXIT_FAILURE;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;
    
    }else if( arg == "3"){
        g.board.fromString("---------B--------------------------b---------------------------");
        g.drawBoard();

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            to_test = pdp_chess::legal_move(g.board,true);

            if (to_test.size() != 6){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if( (int)m.start_position != 9){
                    return EXIT_FAILURE;
                }else if( ((int)m.target_position != 0) && ((int)m.target_position != 16) &&((int)m.target_position != 2) && ((int)m.target_position != 18) && ((int)m.target_position != 27) && ((int)m.target_position != 36) ){
                    return EXIT_FAILURE;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;

    }else if( arg == "4"){
        g.board.fromString("P----------n-----N----------------------------------------------");
        g.drawBoard();

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            to_test = pdp_chess::legal_move(g.board,true);

            if (to_test.size() != 6){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if( (int)m.start_position != 17 && m.start_position != a1){
                    return EXIT_FAILURE;
                }else if( ((int)m.target_position != 2) && ((int)m.target_position != 11) && ((int)m.target_position != 27) && ((int)m.target_position != 32) && ((int)m.target_position != 34) && m.target_position != a2){
                    return EXIT_FAILURE;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;

    }else if( arg == "5"){
        g.board.fromString("-----P-Q--------------------q----------p------------------------");
        g.drawBoard();

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            to_test = pdp_chess::legal_move(g.board,true);

            if (to_test.size() != 9){
                return EXIT_FAILURE;
            }

            for( Move m : to_test){
                if ( (int)m.start_position != 7 && m.start_position != f1){
                    return EXIT_FAILURE;
                }else if( ((int)m.target_position != 6) && ((int)m.target_position != 14) && ((int)m.target_position != 21) && ((int)m.target_position != 28) && ((int)m.target_position != 15) && ((int)m.target_position != 23) && ((int)m.target_position != 31) && ((int)m.target_position != 39) && m.target_position != f2){
                    return EXIT_FAILURE;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;

    }else if( arg == "6"){
        g.board.fromString("K-------p------p------------------------------------------------");
        g.drawBoard();

        auto begin = std::chrono::high_resolution_clock::now();
        uint32_t iterations = 1000000;
        for(uint32_t i = 0; i < iterations; ++i)
        {
            to_test = pdp_chess::legal_move(g.board,true);

            if (to_test.size() != 3){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if ( (int)m.start_position != 0){
                    return EXIT_FAILURE;
                }else if( ((int)m.target_position != 1) && ((int)m.target_position != 8) && ((int)m.target_position != 9) ){
                    return EXIT_FAILURE;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl;

        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}