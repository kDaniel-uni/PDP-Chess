//
// Pdp_chess university project
//

#ifndef PDP_CHESS_HEURISTIC_H
#define PDP_CHESS_HEURISTIC_H

#include "board.h"

namespace pdp_chess {

    class Heuristic {
    public :
        int pawns_value;
        int rooks_value;
        int bishops_value;
        int knights_value;
        int queen_value;
        int king_value;
        int backward_value;
        int isolated_value;
        int doubled_value;

        Heuristic();
        int nbIsolated(const Bitboard &bitboard);
    };

}

#endif //PDP_CHESS_HEURISTIC_H