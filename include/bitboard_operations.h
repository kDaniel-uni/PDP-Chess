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

}


namespace filters{

    uint64_t get_white_pawns_in_base_position(Bitboard bitboard);

    uint64_t get_black_pawns_in_base_position(Bitboard bitboard);
}

#endif //PDP_ECHEC_BITBOARD_OPERATIONS_H
