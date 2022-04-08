//
// Pdp_chess university project
//

#ifndef PDP_CHESS_HUMAN_PLAYER_H
#define PDP_CHESS_HUMAN_PLAYER_H

#include "player.h"
#include "legal_move_v2.h"

namespace pdp_chess {

    class HumanPlayer : Player{
    private:
        Legalmove* legal_move;

        HumanPlayer();
        Move askNextMove(Board& board, color current_color) override;
    };

}

#endif //PDP_CHESS_HUMAN_PLAYER_H
