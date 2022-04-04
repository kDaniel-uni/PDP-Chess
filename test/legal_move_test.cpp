//
// Pdp_chess university project
//

#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "game.h"
#include "legal_move.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {
    std::string arg = argv[1];
    Game g = Game();
    std::vector<Move> to_test;

    if (arg == "1"){
        g.board.fromString("--------P--------p----------------------------------------------");
        g.drawBoard();

        to_test = pdp_chess::legal_move_pawns(g.board,true);

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

        to_test = pdp_chess::legal_move_pawns(g.board,false);

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
        return EXIT_SUCCESS;

    }else if( arg == "2"){
        g.board.fromString("R---------------r-----------------------------------------------");
        g.drawBoard();

        to_test = pdp_chess::legal_move_rooks(g.board,true);

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
        return EXIT_SUCCESS;
    
    }else if( arg == "3"){
        g.board.fromString("---------B--------------------------b---------------------------");
        g.drawBoard();

        to_test = pdp_chess::legal_move_bishops(g.board,true);

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
        return EXIT_SUCCESS;
    }else if( arg == "4"){
        g.board.fromString("P----------n-----N----------------------------------------------");
        g.drawBoard();

        to_test = pdp_chess::legal_move_knights(g.board,true);

        if (to_test.size() != 5){
            return EXIT_FAILURE;
        }

        for(Move m : to_test){
            if( (int)m.start_position != 17){
                return EXIT_FAILURE;
            }else if( ((int)m.target_position != 2) && ((int)m.target_position != 11) && ((int)m.target_position != 27) && ((int)m.target_position != 32) && ((int)m.target_position != 34) ){
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }else if( arg == "5"){
        g.board.fromString("-----P-Q--------------------q----------p------------------------");
        g.drawBoard();

        to_test = pdp_chess::legal_move_queen(g.board,true);

        if (to_test.size() != 8){
            return EXIT_FAILURE;
        }

        for( Move m : to_test){
            if ( (int)m.start_position != 7){
                return EXIT_FAILURE;
            }else if( ((int)m.target_position != 6) && ((int)m.target_position != 14) && ((int)m.target_position != 21) && ((int)m.target_position != 28) && ((int)m.target_position != 15) && ((int)m.target_position != 23) && ((int)m.target_position != 31) && ((int)m.target_position != 39) ){
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }else if( arg == "6"){
        g.board.fromString("K-------p------p------------------------------------------------");
        g.drawBoard();

        to_test = pdp_chess::legal_move_king(g.board,true);

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
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}