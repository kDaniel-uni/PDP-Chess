//
// Pdp_chess university project
//

#include "ai_factory.h"
#include <string>
#include <iostream>

namespace pdp_chess {

    AiFactory::AiFactory(LegalMove &legal_move) {
        _legal_move = &legal_move;
    }

    AiPlayer &pdp_chess::AiFactory::createAiPlayer(Json::Value& ai_data) {
        std::string ai_name = ai_data["Type"].asCString();
        if (ai_name.compare("AlphaBeta") == 0) {
            return createMinMaxAB(ai_data);
        }

        std::cout << "Cannot find AI type, creating random player" << std::endl;
        return createRandom();
    }

    MinMaxAb &AiFactory::createMinMaxAB(Json::Value ai_data) {
        Heuristic* heuristic = new Heuristic(ai_data["Heuristic"]);
        int depth = ai_data["Depth"].asInt();

        MinMaxAb* alpha_beta = new MinMaxAb(*heuristic, *_legal_move, depth);
        return *alpha_beta;
    }

    RandomPlayer &AiFactory::createRandom() {
        RandomPlayer* random_player = new RandomPlayer(*_legal_move);
        return *random_player;
    }
}

