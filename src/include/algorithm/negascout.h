//
// Pdp_chess university project
//

#ifndef PDP_CHESS_NEGASCOUT_H
#define PDP_CHESS_NEGASCOUT_H

#include <string>
#include "move.h"
#include "heuristic.h"
namespace pdp_chess {

    class Negascout : public AIPlayer{

        public:
            Negascout(Heuristic& h, LegalMove& l, int depth);

            Move askNextMove(Board& board, color current_color);
            int algoNegaScout(Board board, int depth, int alpha, int beta, bool current_color);
    };

}

#endif //PDP_CHESS_NEGASCOUT_H
