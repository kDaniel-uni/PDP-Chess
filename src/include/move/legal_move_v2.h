#ifndef PDP_CHESS_LEGAL_MOVE_V2_H
#define PDP_CHESS_LEGAL_MOVE_V2_H



#include <cstdint>
#include "bitboards.h"
#include <iostream>
#include <vector>
#include "board.h"
#include "move.h"

namespace pdp_chess {
    uint64_t const not_a_border = 18374403900871474942ULL;
    uint64_t const not_h_border = 9187201950435737471ULL;


    std::vector<Move> legalMove(const Board& board, bool white);

    uint64_t pawnsAttacks(int color, int position); // color {white = 0 ; black = 1}

    std::string bitboardToString(uint64_t mask);// for a debug usage
    void printBitboard(uint64_t mask); // for a debug usage


}

#endif //PDP_CHESS_LEGAL_MOVE_V2_H