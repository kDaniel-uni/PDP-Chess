//
// Pdp_chess university project
//

#ifndef PDP_CHESS_LEGAL_MOVE_H
#define PDP_CHESS_LEGAL_MOVE_H

#include <vector>
#include "move.h"

namespace pdp_chess {

    class LegalMove {
    public:
        virtual ~LegalMove() {}

        virtual std::vector<Move> getLegalMoves(const Board &board, bool playing_color) = 0;
    };

}

#endif //PDP_CHESS_LEGAL_MOVE_H
