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

    void eatPiece(uint8_t index, Bitboards& bitboards);

    void movePiece(uint64_t mask, Bitboard& bitboard);

    uint64_t getWhitePawnsInBasePosition(const Bitboard& bitboard);

    uint64_t getBlackPawnsInBasePosition(const Bitboard& bitboard);

}

#endif //PDP_CHESS_BITBOARD_OPERATIONS_H
