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

    std::vector<uint8_t> get_positions(Bitboard bitboard);

    std::string to_string(Bitboards* bitboards);

    Bitboards* from_string(const char* data);

    void draw_board(Bitboards* bitboards);

    Bitboard get_bitboard_to_index(Bitboards* bitboards, int index);

    Bitboards * traduct_from_move(Bitboards * bitboards,move mv);
}


namespace filters{

    Bitboard get_white_pawns_in_base_position(Bitboard bitboard);

    Bitboard get_black_pawns_in_base_position(Bitboard bitboard);
}

#endif //PDP_ECHEC_BITBOARD_OPERATIONS_H
