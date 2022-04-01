#include "game.h"
#include "legal_move_v2.h"
#include "bitboard_operations.h"

namespace pdp_chess {


uint64_t pawnsAttacks(int color, int position){

    uint64_t bitboard = (base >> position);
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

void initPawnsAttacksTable(){
    
    for(int position = 0; position < 64; position ++){
        pawns_attack_table[white][position] = pawnsAttacks(white,position);
        pawns_attack_table[black][position] = pawnsAttacks(black,position);
    }
}




}