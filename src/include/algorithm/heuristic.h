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

        Heuristic();
        Heuristic(int p_v, int r_v, int b_v, int kn_v, int q_v, int k_v);
        int nbDoubled(const Bitboard &bitboard);
        int nbBackward(const Bitboard &bitboard);
        int nbIsolated(const Bitboard &bitboard);
        int evaluatePieces(const Bitboards * bitboard);
        int evaluateBoard(const Board& board, bool white_turn); //true for white turn, false for black turn
    };

}

#endif //PDP_CHESS_HEURISTIC_H