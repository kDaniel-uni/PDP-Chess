#ifndef PDP_CHESS_LEGAL_MOVE_V2_H
#define PDP_CHESS_LEGAL_MOVE_V2_H

#include "game.h"
#include "bitboards.h"
#include "string"
#include "vector"
#include "move.h"

namespace pdp_chess {
uint64_t base = 1;
uint64_t const not_a_border = (base >> 0) + (base >> 8) + (base >> 16) + (base >> 24) + (base >> 32) + (base >> 40) + (base >> 48) + (base >> 58);
uint64_t const not_h_border = (base >> 7) + (base >> 15) + (base >> 23) + (base >> 31) + (base >> 39) + (base >> 47) + (base >> 57) + (base >> 63);

uint64_t pawns_attack_table[2][64];
uint64_t pawnsAttacks(int color, int position); // color {white = 0 ; black = 1}
void initPawnsAttacksTable();

}

#endif //PDP_CHESS_LEGAL_MOVE_V2_H