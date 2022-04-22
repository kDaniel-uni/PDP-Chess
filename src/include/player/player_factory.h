//
// Pdp_chess university project
//

#ifndef PDP_CHESS_PLAYER_FACTORY_H
#define PDP_CHESS_PLAYER_FACTORY_H

#include <string>
#include <iostream>
#include "orchestration/parameters.h"
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
        PlayerFactory(LegalMove &legal_move);

        Player *createPlayer(const PlayerParameters &player_parameters);

    private:
        LegalMove *_legal_move;

        Player *createHumanPlayer();

        Player *createRandom();

        Player *createMinMaxAB(const AIParameters &ai_parameters);

        Player *createNegaMax(const AIParameters &ai_parameters);

        Player *createNegaScout(const AIParameters &ai_parameters);

        Player *createMTDF(const AIParameters &ai_parameters);

        Player *createMCTS(const AIParameters &ai_parameters);
    };

}

#endif //PDP_CHESS_PLAYER_FACTORY_H
