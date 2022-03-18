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

    char* to_string(Bitboards* bitboards);

    Bitboards* from_string(const char* data);
}

#endif //PDP_ECHEC_BITBOARD_OPERATIONS_H
