//
// Pdp_chess university project
//

    int negaMax(Board board, int depth, bool ai_player_turn);
#ifndef PDP_CHESS_NEGAMAX_H
#define PDP_CHESS_NEGAMAX_H

#include <string>
#include "ai_player.h"
#include "vector_shuffle.h"

namespace pdp_chess{

    class Negamax : public AIPlayer{

        public:
            Negamax(Heuristic& h, LegalMove& l, int depth);

            Move askNextMove(Board& board, color current_color) override;
            int algoNega(Board board, int depth, bool current_color, bool base_color);
    };
}

#endif //PDP_CHESS_NEGAMAX_H