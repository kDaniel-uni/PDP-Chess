//
// Created by KAAAAAAAAAAAAAAAAARL on 18/03/2022.
//

#include "../include/bitboard_operations.h"
namespace bitboard_operation{

    std::string bitboard_to_string(uint64_t * bitboard, char p){
        std::string res;
        for(int i=0;i<sizeof(bitboard);i++){
            if(bitboard[i] == 0){
                res[i] = '-';
            }
            else{
                res[i] = p;
            }
        }
        return res;
    }
}

