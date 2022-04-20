//
// Pdp_chess university project
//

#ifndef PDP_CHESS_RANDOM_PLAYER_H
#define PDP_CHESS_RANDOM_PLAYER_H

#include "ai_player.h"

namespace pdp_chess {

    class RandomPlayer : public Player {

    public:
        RandomPlayer(LegalMove& legal_move);

        Move askNextMove(Board& board, color current_color) override;

    private:
        LegalMove* _legal_move;
    };

}

#endif //PDP_CHESS_RANDOM_PLAYER_H
