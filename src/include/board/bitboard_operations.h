//
// Pdp_chess university project
//

#ifndef PDP_CHESS_BITBOARD_OPERATIONS_H
#define PDP_CHESS_BITBOARD_OPERATIONS_H

#include "string"
#include "vector"
#include "bitboards.h"
#include "move.h"

namespace pdp_chess{

    std::vector<uint8_t> getPositions(const Bitboard& bitboard);

    std::vector<uint8_t> getPositionsV2(uint64_t bitboard);

    void eatPiece(Move& move, PlayerState& player_state);

    void movePiece(Move& move, PlayerState& player_state);

    void createPiece(Move& move, PlayerState& player_state);

    uint64_t getWhitePawnsInBasePosition(const Bitboard& bitboard);

    uint64_t getBlackPawnsInBasePosition(const Bitboard& bitboard);

}

#endif //PDP_CHESS_BITBOARD_OPERATIONS_H
