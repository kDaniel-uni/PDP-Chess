//
// Pdp_chess university project
//

#ifndef PDP_CHESS_NEGASCOUT_H
#define PDP_CHESS_NEGASCOUT_H

#include "ai_player.h"

namespace pdp_chess {
    class NegaScout : public AIPlayer{


        Move findNextMove(Board& board, color current_color){

        }

        std::string getParameters(){

        }
    };
            int NegaScout(Board board, int depth, int alpha, int beta, bool current_color, bool base_color);
}

#endif //PDP_CHESS_NEGASCOUT_H

    int NegaScout(Board board, int depth, int alpha, int beta, boolean ai_player_turn);