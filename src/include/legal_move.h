//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_LEGAL_MOVE_H
#define PDP_ECHEC_LEGAL_MOVE_H
#include "game.h"
#include "bitboards.h"
#include "string"
#include "vector"
#include "move.h"

namespace pdp_chess{
    void move_this_position(const board& board,uint8_t position_start, uint8_t position_target, uint8_t position_x_target, bool color_piece, std::vector<movement>& res);
    void move_line_vertical_horizontal(const board& board, uint8_t position_start, bool color_piece, std::vector<movement>& res);
    void move_diagonal(const board& board, uint8_t position_start, bool color_piece, std::vector<movement>& res);
    std::vector<movement> legal_move(const board& board, bool white);
    std::vector<movement> legal_move_pawns(const board& board, bool white);
    std::vector<movement> legal_move_rooks(const board& board, bool white);
    std::vector<movement> legal_move_knights(const board& board, bool white);
    std::vector<movement> legal_move_bishops(const board& board, bool white);
    std::vector<movement> legal_move_queen(const board& board, bool white);
    std::vector<movement> legal_move_king(const board& board, bool white);
}

#endif //PDP_ECHEC_LEGAL_MOVE_H