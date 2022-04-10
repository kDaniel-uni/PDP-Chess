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
        int legal_move_value;
        int forward_pawn_value;

        Heuristic();
        Heuristic(int p_v, int r_v, int b_v, int kn_v, int q_v, int k_v, int back_v, int i_v, int d_v, int lm_v);
        int nbDoubled(const Bitboard &bitboard);
        int blackNbBackward(const Bitboard &bitboard);
        int whiteNbBackward(const Bitboard &bitboard);
        int nbIsolated(const Bitboard &bitboard);
        int pawnForward(const Bitboard &current_pawns, const Bitboard &opponent_pawns);
        int nbLegalMove(const Board& board, bool white_turn);
        int evaluatePieces(const PlayerState& player_state, bool is_white);
        int evaluateBoard(const Board &board, bool color);
    };

}

#endif //PDP_CHESS_HEURISTIC_H