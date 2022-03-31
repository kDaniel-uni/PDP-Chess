//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARDS_H
#define PDP_ECHEC_BITBOARDS_H

#include "heuristic.h"

namespace pdp_chess {

    const int BOARD_SIZE = 64;

    enum color{
        black = false,
        white = true
    };

    struct Bitboard {
        uint64_t value;
        char type;
    };

    struct Bitboards {
        Bitboard pawns;

        Bitboard rooks;

        Bitboard knights;

        Bitboard bishops;

        Bitboard queen;

        Bitboard king;

        Bitboard all;

        Bitboard* list[6];

        Bitboards(bool is_white, bool is_empty);

        int getBitboardValue(Heuristic *h);
    };

}

#endif //PDP_ECHEC_BITBOARDS_H
