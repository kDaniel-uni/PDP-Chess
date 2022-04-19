//
// Pdp_chess university project
//

#ifndef PDP_CHESS_AI_PLAYER_H
#define PDP_CHESS_AI_PLAYER_H

#include <string>
#include "player.h"
#include "move.h"
#include "heuristic.h"
#include "legal_move.h"

namespace pdp_chess {

    class AiPlayer : public Player{
        

    public :
        Heuristic* _heuristic;
        LegalMove* _legal_move;
        int _depth;
        
        virtual ~AiPlayer() {}
        Move askNextMove(Board& board, color current_color) override = 0;
    };

}

#endif //PDP_CHESS_AI_PLAYER_H
