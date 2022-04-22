//
// Pdp_chess university project
//

#ifndef PDP_CHESS_LEGAL_MOVE_V1_H
#define PDP_CHESS_LEGAL_MOVE_V1_H

#include <string>
#include "board.h"
#include "legal_move.h"
#include "bitboard_operations.h"

namespace pdp_chess {

    class LegalMoveV1 : public LegalMove {
    private:
        void
        moveThisPosition(const Board &board, uint8_t position_start, uint8_t position_target, uint8_t position_x_target,
                         bool color_piece, std::vector<Move> &res);

        void moveLineVerticalHorizontal(const Board &board, uint8_t position_start, bool color_piece,
                                        std::vector<Move> &res);

        void moveDiagonal(const Board &board, uint8_t position_start, bool color_piece, std::vector<Move> &res);

        std::vector<Move> legal_move_pawns(const Board &board, bool white);

        std::vector<Move> legal_move_rooks(const Board &board, bool white);

        std::vector<Move> legal_move_bishops(const Board &board, bool white);

        std::vector<Move> legal_move_knights(const Board &board, bool white);

        std::vector<Move> legal_move_queen(const Board &board, bool white);

        std::vector<Move> legal_move_king(const Board &board, bool white);

    public:
        std::vector<Move> getLegalMoves(const Board &board, bool playing_color) override;
    };
}

#endif //PDP_CHESS_LEGAL_MOVE_V1_H