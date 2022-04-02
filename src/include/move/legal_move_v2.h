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
    uint64_t const not_ab_border = 18229723555195321596ULL;
    uint64_t const not_gh_border = 4557430888798830399ULL;


    std::vector<Move> legalMove(const Board& board, bool white);

    uint64_t pawnsAttacks(int color, int position); // color {black = 0 ; white = 1}
    uint64_t pawnsMove(int color, int position);
    uint64_t knightsMove(int position);
    uint64_t kingsMoves(int position);

    std::string bitboardToString(uint64_t mask);// for a debug usage
    void printBitboard(uint64_t mask); // for a debug usage


}

#endif //PDP_CHESS_LEGAL_MOVE_V2_H