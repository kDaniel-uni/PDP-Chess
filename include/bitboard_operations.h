//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARD_OPERATIONS_H
#define PDP_ECHEC_BITBOARD_OPERATIONS_H

#include "string"
#include "vector"
#include "bitboards.h"

namespace io_bitboard{

    std::vector<uint8_t> get_positions(Bitboard bitboard);

    std::string to_string(Bitboards* bitboards);

    Bitboards* from_string(const char* data);

    void draw_board(Bitboards* bitboards);
}


namespace filters{

    Bitboard get_white_pawns_in_base_position(Bitboard bitboard);

    Bitboard get_black_pawns_in_base_position(Bitboard bitboard);
}

#endif //PDP_ECHEC_BITBOARD_OPERATIONS_H
