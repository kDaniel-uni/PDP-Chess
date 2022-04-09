//
// Pdp_chess university project
//

#ifndef PDP_CHESS_LEGAL_MOVE_H
#define PDP_CHESS_LEGAL_MOVE_H

#include "game.h"
#include "player_state.h"
#include "string"
#include "vector"
#include "move.h"

namespace pdp_chess {

    void moveThisPosition(const Board& board, uint8_t position_start, uint8_t position_target, uint8_t position_x_target, bool color_piece, std::vector<Move>& res);
    void moveLineVerticalHorizontal(const Board& board, uint8_t position_start, bool color_piece, std::vector<Move>& res);
    void moveDiagonal(const Board& board, uint8_t position_start, bool color_piece, std::vector<Move>& res);
    std::vector<Move> legal_move(const Board& board, bool white);
    std::vector<Move> legal_move_pawns(const Board& board, bool white);
    std::vector<Move> legal_move_rooks(const Board& board, bool white);
    std::vector<Move> legal_move_bishops(const Board& board, bool white);
    std::vector<Move> legal_move_knights(const Board& board, bool white);
    std::vector<Move> legal_move_queen(const Board& board, bool white);
    std::vector<Move> legal_move_king(const Board& board, bool white);

}

#endif //PDP_CHESS_LEGAL_MOVE_H