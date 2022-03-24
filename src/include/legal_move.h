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
    std::vector<movement> legal_move(const board& board, bool white);
    std::vector<movement> legal_move_pawns(const board& board, bool white);
    std::vector<movement> legal_move_rooks(const board& board, bool white);
    std::vector<movement> legal_move_knights(const board& board, bool white);
    std::vector<movement> legal_move_bishops(const board& board, bool white);
    std::vector<movement> legal_move_queen(const board& board, bool white);
    std::vector<movement> legal_move_king(const board& board, bool white);
}

#endif //PDP_ECHEC_LEGAL_MOVE_H