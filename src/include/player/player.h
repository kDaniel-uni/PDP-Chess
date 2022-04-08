//
// Pdp_chess university project
//

#ifndef PDP_CHESS_PLAYER_H
#define PDP_CHESS_PLAYER_H

#include "board.h"

namespace pdp_chess {

    class Player {
    public:
        virtual ~Player() {}
        virtual Move askNextMove(Board& board, color current_color) = 0;
    };

}

#endif //PDP_CHESS_PLAYER_H
