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
            int algoNega(Board board, int depth, bool current_color, bool base_color);
    };
}

#endif //PDP_CHESS_NEGAMAX_H