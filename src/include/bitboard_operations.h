//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARD_OPERATIONS_H
#define PDP_ECHEC_BITBOARD_OPERATIONS_H

#include "string"
#include "vector"
#include "bitboards.h"
#include "move.h"

namespace io_bitboard{

    std::vector<uint8_t> get_positions(const Bitboard& bitboard);

    void eat_piece(uint8_t index, Bitboards& bitboards);

    void move_piece(uint64_t mask, Bitboard& bitboard);

}


namespace filters{

    uint64_t get_white_pawns_in_base_position(const Bitboard& bitboard);

    uint64_t get_black_pawns_in_base_position(const Bitboard& bitboard);
}

#endif //PDP_ECHEC_BITBOARD_OPERATIONS_H
