//
// Pdp_chess university project
//

#ifndef PDP_CHESS_AI_PLAYER_H
#define PDP_CHESS_AI_PLAYER_H

#include <string>
#include "player.h"
#include "valuation/heuristic.h"

namespace pdp_chess {

    class AIPlayer : public Player{
    public :
        Heuristic* _heuristic;
        int _depth;

        AIPlayer(LegalMove &legalMove, Heuristic &heuristic, int depth) : Player(legalMove) {
            _heuristic = &heuristic;
            _depth = depth;
        }

        virtual ~AIPlayer() {}
        Move askNextMove(Board& board, color current_color) override = 0;
    };

}

#endif //PDP_CHESS_AI_PLAYER_H
