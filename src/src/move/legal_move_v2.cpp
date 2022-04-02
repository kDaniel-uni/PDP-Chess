
#include "legal_move_v2.h"
#include <math.h>

namespace pdp_chess {

    uint64_t pawnsMove(int color, int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if(color){
            if( (position > 7) & (position < 16) ){
                mask |= (bitboard << 16);
            }
            mask |= (bitboard << 8);
        }

        else{
            if( (position > 47) & (position < 56) ){
                mask |= (bitboard >> 16);
            }
            mask |= (bitboard >> 8);
        }

        return mask;
    }

    uint64_t pawnsAttacks(int color, int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if(color){
            if((bitboard << 7) & not_h_border){
                mask |= (bitboard << 7);
            }
            if((bitboard << 9) & not_a_border){
                mask |= (bitboard << 9);
            }
        }

        else{
            if((bitboard >> 7) & not_a_border){
                mask |= (bitboard >> 7);
            }
            if((bitboard >> 9) & not_h_border){
                mask |= (bitboard >> 9);
            }
        }

        return mask;
    }

    uint64_t knightsMove(int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if( (bitboard >> 17) & not_h_border){
            mask |= (bitboard >> 17);
        }
        if( (bitboard >> 15) & not_a_border){
            mask |= (bitboard >> 15);
        }
        if( (bitboard >> 10) & not_gh_border){
            mask |= (bitboard >> 10);
        }
        if( (bitboard >> 6) & not_ab_border){
            mask |= (bitboard >> 6);
        }

        if( (bitboard << 17) & not_a_border){
            mask |= (bitboard << 17);
        }
        if( (bitboard << 15) & not_h_border){
            mask |= (bitboard << 15);
        }
        if( (bitboard << 10) & not_ab_border){
            mask |= (bitboard << 10);
        }
        if( (bitboard << 6) & not_gh_border){
            mask |= (bitboard << 6);
        }

        return mask;
    }
    uint64_t kingsMoves(int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if((bitboard << 7) & not_h_border){
            mask |= (bitboard << 7);
        }
        if((bitboard << 9) & not_a_border){
            mask |= (bitboard << 9);
        }
        if((bitboard << 1) & not_a_border){
            mask |= (bitboard << 1);
        }
        if((bitboard >> 1) & not_h_border){
            mask |= (bitboard >> 1);
        }
        if((bitboard >> 7) & not_a_border){
            mask |= (bitboard >> 7);
        }
        if((bitboard >> 9) & not_h_border){
            mask |= (bitboard >> 9);
        }

        mask |= (bitboard << 8);
        mask |= (bitboard >> 8);
        return mask;
        
    }

    std::string bitboardToString(uint64_t mask){
        std::string res;
        res.resize(64);
        int dec = BOARD_SIZE-1;

        for(int i = 0; i<BOARD_SIZE; i++){
            if((mask >> i)&1){
                res[dec] = '1';
            }
            else{
                res[dec] = '0';
            }
            dec--;
        }
        
        return res + std::to_string(mask);
    }

    void printBitboard(uint64_t mask){
        std::string chars = bitboardToString(mask);
        for (int current_y = 0; current_y <= 7; current_y++){
                for (int current_x = 7; current_x >= 0; current_x--){
                    std::cout << chars[current_y * 8 + current_x] << ' ';
                }
                std::cout << std::endl;
            }
        std::cout<< "Valeur totale du bitboard : "<< std::endl;
        std::cout << chars.substr(64) << std::endl;
    }

    std::vector<Move> legalMove(const Board& board, bool white){
        // init lookup table attacks
        uint64_t pawns_attack_table[2][64];
        uint64_t pawns_move_table[2][64];
        uint64_t knights_move[64];
        uint64_t kings_moves_table[64];
        for(int position = 0; position < 64; position ++){
            pawns_attack_table[white][position] = pawnsAttacks(white,position);
            pawns_attack_table[black][position] = pawnsAttacks(black,position);
            pawns_move_table[white][position] = pawnsMove(white,position);
            pawns_move_table[black][position] = pawnsMove(black,position);
            knights_move[position] = knightsMove(position);
            kings_moves_table[position]= kingsMoves(position);
        }
        std::vector<Move> moves;
        return moves;
    }


}