//
// Pdp_chess university project
//

#ifndef PDP_CHESS_PLAYER_FACTORY_H
#define PDP_CHESS_PLAYER_FACTORY_H

#include "parameters.h"
#include "human_player.h"
#include "minmax_ab.h"
#include "negamax.h"
#include "negascout.h"
#include "random_player.h"
#include "mcts.h"
#include "mtdf.h"
#include "legal_move.h"

namespace pdp_chess {

    class PlayerFactory {
    public:
        PlayerFactory(LegalMove &legalMove);
        Player& CreatePlayer(const PlayerParameters &playerParameters);

    private:
        LegalMove* _legal_move;

        HumanPlayer& CreateHumanPlayer();
        RandomPlayer& CreateRandom();
        MinMaxAb& CreateMinMaxAB(const AIParameters &aiParameters);
        Negamax& CreateNegaMax(const AIParameters &aiParameters);
        NegaScout& CreateNegaScout(const AIParameters &aiParameters);
        MTDF& CreateMTDF(const AIParameters &aiParameters);
        MCTS& CreateMCTS(const AIParameters &aiParameters);
    };

}

#endif //PDP_CHESS_PLAYER_FACTORY_H
