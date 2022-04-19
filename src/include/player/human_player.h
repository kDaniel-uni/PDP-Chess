//
// Pdp_chess university project
//

#ifndef PDP_CHESS_HUMAN_PLAYER_H
#define PDP_CHESS_HUMAN_PLAYER_H

#include "player.h"
#include "legal_move_v2.h"

namespace pdp_chess {

    class HumanPlayer : public Player{
    public:
        LegalMove* _legal_move;
        std::string _move_map[64];

        HumanPlayer(LegalMove &legal_move);
        Move askNextMove(Board& board, color current_color) override;
        void initMoveMap();
        Move moveFromString(std::string mv);
    };


}

#endif //PDP_CHESS_HUMAN_PLAYER_H
