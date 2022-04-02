
#include "legal_move_v2.h"


namespace pdp_chess {


    uint64_t pawnsAttacks(int color, int position){
        uint64_t b;
        uint64_t bitboard = (b >> position);
        uint64_t mask = 0;

        if(color){
            if((bitboard >> 7) & not_a_border){
                mask |= (bitboard >> 7);
            }
            if((bitboard >> 9) & not_h_border){
                mask |= (bitboard >> 9);
            }
        }

        else{
            if((bitboard << 7) & not_h_border){
                mask |= (bitboard << 7);
            }
            if((bitboard << 9) & not_a_border){
                mask |= (bitboard << 9);
            }
        }

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
        for(int position = 0; position < 64; position ++){
            pawns_attack_table[white][position] = pawnsAttacks(white,position);
            pawns_attack_table[black][position] = pawnsAttacks(black,position);
        }
        std::vector<Move> moves;
        return moves;
    }


}