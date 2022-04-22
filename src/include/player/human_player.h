//
// Pdp_chess university project
//

#ifndef PDP_CHESS_HUMAN_PLAYER_H
#define PDP_CHESS_HUMAN_PLAYER_H

#include "player.h"

namespace pdp_chess {

    class HumanPlayer : public Player{
    public:
        std::string _move_map[64];

        HumanPlayer(LegalMove &legal_move);
        Move askNextMove(Board& board, color current_color) override;
        void initMoveMap();
        Move moveFromString(std::string string_move);
    };


}

#endif //PDP_CHESS_HUMAN_PLAYER_H
