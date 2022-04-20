//
// Pdp_chess university project
//

#ifndef PDP_CHESS_NEGASCOUT_H
#define PDP_CHESS_NEGASCOUT_H

#include "ai_player.h"

namespace pdp_chess {
    class NegaScout : public AIPlayer{

        public:
            NegaScout(Heuristic& heuristic, LegalMove& legalMove, int depth);
            Move askNextMove(Board& board, color current_color) override;
            int algoNegaScout(Board board, int depth, int alpha, int beta, bool current_color, bool base_color);

            std::string getParameters();
    };
}

#endif //PDP_CHESS_NEGASCOUT_H
