//
// Pdp_echec university project
//

#include "../include/bitboard_operations.h"
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

    uint64_t get_white_pawns_in_base_position(Bitboard bitboard){
        uint64_t white_pawn_base_position = 71776119061217280;
        return bitboard.value & white_pawn_base_position;
    }

    uint64_t get_black_pawns_in_base_position(Bitboard bitboard){
        uint64_t black_pawn_base_position = 65280;
        return bitboard.value & black_pawn_base_position;
    }

}

