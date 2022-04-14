//
// Pdp_chess university project
//

    int mtdf(Board board, int f, int depth);
#ifndef PDP_CHESS_MTDF_H
#define PDP_CHESS_MTDF_H

#include "ai_player.h"

namespace pdp_chess{

    class MTDF: public AIPlayer{


        Move findNextMove(Board& board, color current_color){

        }

        std::string getParameters(){

        }
    };

            int mtdf(Board board, int f, int depth, bool current_color, bool base_color);
            int AlphaBetaWithMemory(Board board, int depth, int alpha, int beta, bool current_color, bool base_color);
}

#endif //PDP_CHESS_MTDF_H
