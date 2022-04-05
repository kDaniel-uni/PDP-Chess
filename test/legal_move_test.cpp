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
                if(m.start_position != a2 ){
                    return EXIT_FAILURE;
                }
                else{
                    if(m.target_position != a4 && m.target_position != a3 && m.target_position != b3 ){
                        return EXIT_FAILURE;
                    }
                }
            }

            to_test = pdp_chess::legal_move(g.board,false);

            if (to_test.size() != 2){
                return EXIT_FAILURE;
            }

            for(Move m : to_test){
                if(m.start_position != b3 ){
                    return EXIT_FAILURE;
                }
                else{
                    if( m.target_position != b2 && m.target_position != a2 ){
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
                if(m.start_position != a1 ){
                    return EXIT_FAILURE;
                }else if( m.target_position != a2 && m.target_position != a3 && m.target_position != b1 && m.target_position != c1 && m.target_position != d1 && m.target_position != e1 && m.target_position != f1 && m.target_position != g1 && m.target_position != h1 ){
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
                if( m.start_position != b2){
                    return EXIT_FAILURE;
                }else if( m.target_position != a1 && m.target_position != a3 &&m.target_position != c1 && m.target_position != c3 && m.target_position != d4 && m.target_position != e5 ){
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
                if( m.start_position != b3 && m.start_position != a1){
                    return EXIT_FAILURE;
                }else if( m.target_position != c1 && m.target_position != d2 && m.target_position != d4 && m.target_position != a5 && m.target_position != c5 && m.target_position != a2){
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
                if ( m.start_position != h1 && m.start_position != f1){
                    return EXIT_FAILURE;
                }else if( m.target_position != g1 && m.target_position != g2 && m.target_position != f3 && m.target_position != e4 && m.target_position != h2 && m.target_position != h3 && m.target_position != h4 && m.target_position != h5 && m.target_position != f2){
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
                if (m.start_position != a1){
                    return EXIT_FAILURE;
                }else if( m.target_position != b1 && m.target_position != a2 && m.target_position != b2 ){
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