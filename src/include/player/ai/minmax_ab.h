//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MINMAX_AB_H
#define PDP_CHESS_MINMAX_AB_H

#include <string>
#include "ai_player.h"
#include "vector_shuffle.h"

namespace pdp_chess {

    class MinMaxAb : public AIPlayer{

        public:
            MinMaxAb(Heuristic& heuristic, LegalMove& legal_move, int depth);
            Move askNextMove(Board& board, color current_color) override;

        private:
            int alphaBeta(Board board, int depth, int alpha, int beta, bool current_color, bool base_color);
            int betaAlpha(Board board, int depth, int alpha, int beta, bool current_color, bool base_color);
    };

}

#endif //PDP_CHESS_MINMAX_AB_H
