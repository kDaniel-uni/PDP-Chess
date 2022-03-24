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

