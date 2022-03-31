//
// Pdp_chess university project
//

#ifndef PDP_CHESS_AI_PLAYER_H
#define PDP_CHESS_AI_PLAYER_H

#include <string>
#include "move.h"
#include "heuristic.h"

namespace pdp_chess {

    class AiPlayer {
    private :
        Heuristic _heuristic;

    public :
        virtual ~AiPlayer() {}
        virtual Move findNextMove(Board& board, color current_color) = 0;
        virtual std::string getParameters() = 0;

    };

}

#endif //PDP_CHESS_AI_PLAYER_H
