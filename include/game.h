//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_GAME_H
#define PDP_ECHEC_GAME_H


#include "ai_player.h"
#include "board.h"
#include "bitboard_operations.h"
#include <vector>

class game {
public:
    game();
    void drawBoard();
    board* _board;

private:
    ai_player* _white_player;
    ai_player* _black_player;
    ai_player* _current_player;
    std::vector<move> _history;
};


#endif //PDP_ECHEC_GAME_H
