//
// Pdp_chess university project
//

#ifndef PDP_CHESS_NEGAMAX_H
#define PDP_CHESS_NEGAMAX_H

#include <string>
#include "move.h"
#include "heuristic.h"
namespace pdp_chess{

    class Negamax : public AiPlayer{

        public:
            Negamax(Heuristic& h, LegalMove& l, int depth);

            Move askNextMove(Board& board, color current_color) override;
            int algoNegaMax(Board board, int depth, int alpha, int beta, bool current_color);
    };
}

#endif //PDP_CHESS_NEGAMAX_H