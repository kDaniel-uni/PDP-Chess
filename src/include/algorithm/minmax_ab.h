//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MINMAX_AB_H
#define PDP_CHESS_MINMAX_AB_H

namespace pdp_chess {

    class MinMaxAb : public AiPlayer{

        MinMaxAb();

        int minmax_alphabeta(Board board, int depth, int alpha, int beta, bool ai_player_turn);
    };

}

#endif //PDP_CHESS_MINMAX_AB_H
