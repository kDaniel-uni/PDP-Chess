//
// Pdp_chess university project
//

#ifndef PDP_CHESS_PLAYER_FACTORY_H
#define PDP_CHESS_PLAYER_FACTORY_H

#include <string>
#include <iostream>
#include "parameters.h"
#include "player.h"
#include "human_player.h"
#include "minmax_ab.h"
#include "negamax.h"
#include "negascout.h"
#include "random_player.h"
#include "mcts.h"
#include "mtdf.h"

namespace pdp_chess {

    class PlayerFactory {
    public:
        PlayerFactory(LegalMove &legalMove);
        Player* createPlayer(const PlayerParameters &playerParameters);

    private:
        LegalMove* _legal_move;

        Player* createHumanPlayer();
        Player* createRandom();
        Player* createMinMaxAB(const AIParameters &aiParameters);
        Player* createNegaMax(const AIParameters &aiParameters);
        Player* createNegaScout(const AIParameters &aiParameters);
        Player* createMTDF(const AIParameters &aiParameters);
        Player* createMCTS(const AIParameters &aiParameters);
    };

}

#endif //PDP_CHESS_PLAYER_FACTORY_H
