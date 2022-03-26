//
// Pdp_echec university project
//

#include "bitboard_operations.h"
#include <algorithm>
#include <iostream>
#include <math.h>

namespace io_bitboard {

    std::vector<uint8_t> get_positions(const Bitboard& bitboard) {
        std::vector<uint8_t> positions;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((bitboard.value >> i) & 1) {
                positions.push_back(i);
            }
        }
        return positions;
    }


    void eat_piece(uint8_t index, Bitboards& bitboards){
        for(auto pos : io_bitboard::get_positions(bitboards.pawns)){
            if (pos == index){
                bitboards.pawns.value = bitboards.pawns.value - pow(2,index);
                return ;
            }
        }
        for(auto pos : io_bitboard::get_positions(bitboards.bishops)){
            if (pos == index){
                bitboards.bishops.value = bitboards.bishops.value - pow(2,index);
                return ;
            }
        }
        for(auto pos : io_bitboard::get_positions(bitboards.king)){
            if (pos == index){
                bitboards.king.value = bitboards.king.value - pow(2,index);
                return ;
            }
        }
        for(auto pos : io_bitboard::get_positions(bitboards.knights)){
            if (pos == index){
                bitboards.knights.value = bitboards.knights.value - pow(2,index);
                return ;
            }
        }
        for(auto pos : io_bitboard::get_positions(bitboards.queen)){
            if (pos == index){
                bitboards.queen.value = bitboards.queen.value - pow(2,index);
                return ;
            }
        }
        for(auto pos : io_bitboard::get_positions(bitboards.rooks)){
            if (pos == index){
                bitboards.rooks.value = bitboards.rooks.value - pow(2,index);
                return ;
            }
        }
    }
}

namespace filters{

    uint64_t get_white_pawns_in_base_position(const Bitboard& bitboard){
        uint64_t white_pawn_base_position = (1<<15) + (1<<14) + (1<<13) + (1<<12) + (1<<11) + (1<<10) + (1<<9) + (1<<8);
        return bitboard.value & white_pawn_base_position;
    }

    uint64_t get_black_pawns_in_base_position(const Bitboard& bitboard){
        uint64_t base = 1;
        uint64_t black_pawn_base_position = (base<<55) + (base<<54) + (base<<53) + (base<<52) + (base<<51) + (base<<50) + (base<<49) + (base<<48);
        return bitboard.value & black_pawn_base_position;
    }

}

