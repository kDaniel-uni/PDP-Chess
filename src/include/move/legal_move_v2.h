#ifndef PDP_CHESS_LEGAL_MOVE_V2_H
#define PDP_CHESS_LEGAL_MOVE_V2_H

#include "game.h"
#include "bitboards.h"
#include "string"
#include "vector"
#include "move.h"

namespace pdp_chess {
uint64_t base = 1;
uint64_t const not_a_border = 18374403900871474942ULL;
uint64_t const not_h_border = 9187201950435737471ULL;

uint64_t pawns_attack_table[2][64];
uint64_t pawnsAttacks(int color, int position); // color {white = 0 ; black = 1}
void initPawnsAttacksTable();

}

#endif //PDP_CHESS_LEGAL_MOVE_V2_H