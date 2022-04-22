//
// Pdp_chess university project
//

#ifndef PDP_CHESS_PLAYER_H
#define PDP_CHESS_PLAYER_H

#include "board.h"
#include "legal_move.h"

namespace pdp_chess {

    class Player {
    public:
        LegalMove* _legal_move;

        Player(LegalMove &legal_move) {
            _legal_move = &legal_move;
        }
        virtual ~Player() {}
        virtual Move askNextMove(Board& board, color current_color) = 0;
    };

}

#endif //PDP_CHESS_PLAYER_H
