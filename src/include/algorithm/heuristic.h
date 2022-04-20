//
// Pdp_chess university project
//

#ifndef PDP_CHESS_HEURISTIC_H
#define PDP_CHESS_HEURISTIC_H

#include "board.h"
#include "legal_move.h"
#include "orchestration/parameters.h"
#include "bitboard_operations.h"

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
        LegalMove* legalMove;

        Heuristic(LegalMove& legalMove);
        Heuristic(LegalMove& legalMove, const HeuristicParameters &heuristicParameters);
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