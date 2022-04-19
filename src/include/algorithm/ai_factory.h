//
// Pdp_chess university project
//

#ifndef PDP_CHESS_AI_FACTORY_H
#define PDP_CHESS_AI_FACTORY_H

#include "json/json.h"
#include "ai_player.h"
#include "minmax_ab.h"
#include "random_player.h"
#include "legal_move.h"

namespace pdp_chess {

    class AiFactory {
    public:
        AiFactory(LegalMove &legalMove);
        AiPlayer& createAiPlayer(Json::Value& ai_data);

    private:
        LegalMove* _legal_move;

        MinMaxAb& createMinMaxAB(Json::Value ai_data);
        RandomPlayer& createRandom();
    };

}

#endif //PDP_CHESS_AI_FACTORY_H
