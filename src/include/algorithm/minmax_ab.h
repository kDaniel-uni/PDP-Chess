//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MINMAX_AB_H
#define PDP_CHESS_MINMAX_AB_H

#include <string>
#include "move.h"
#include "heuristic.h"

namespace pdp_chess {

    class MinMaxAb : public AiPlayer{

        public:
            MinMaxAb(Heuristic h, Legalmove* l, int depth);

            Move askNextMove(Board& board, color current_color) override;
            int minmax_alphabeta(Board board, int depth, int alpha, int beta, bool ai_player_turn);
    };

}

#endif //PDP_CHESS_MINMAX_AB_H
