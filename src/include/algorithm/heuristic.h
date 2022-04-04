//
// Pdp_chess university project
//

#ifndef PDP_CHESS_HEURISTIC_H
#define PDP_CHESS_HEURISTIC_H

#include "board.h"

namespace pdp_chess {

    class Heuristic {
    public :
        float pawns_value;
        float rooks_value;
        float bishops_value;
        float knights_value;
        float queen_value;
        float king_value;
        float backward_value;
        float isolated_value;
        float doubled_value;

        Heuristic();
        Heuristic(float p_v, float r_v, float b_v, float kn_v, float q_v, float k_v, float back_v, float i_v, float d_v);
        float nbDoubled(const Bitboard  * bitboard);
        float nbBackward(const Bitboard * bitboard);
        float nbIsolated(const Bitboard * bitboard);
        float nbLegalMove(const Board& Board, bool white_turn);
        float evaluatePieces(const Bitboards * bitboard);
        float evaluateBoard(const Board& board, bool white_turn); //true for white turn, false for black turn
    };

}

#endif //PDP_CHESS_HEURISTIC_H