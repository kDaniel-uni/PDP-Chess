//
// Pdp_chess university project
//

#include "player_factory.h"

namespace pdp_chess {

    PlayerFactory::PlayerFactory(LegalMove &legal_move) {
        _legal_move = &legal_move;
    }

    Player* pdp_chess::PlayerFactory::createPlayer(const PlayerParameters &player_parameters) {
        PlayerType playerType = player_parameters.player_type;

        switch (playerType) {
            case Human: return createHumanPlayer();
            case Random: return createRandom();
            case AlphaBeta: return createMinMaxAB(player_parameters.ai_parameters);
            case NegaMax: return createNegaMax(player_parameters.ai_parameters);
            case NegaScout: return createNegaScout(player_parameters.ai_parameters);
            default: return createRandom();
        }
    }

    Player* PlayerFactory::createHumanPlayer() {
        HumanPlayer* humanPlayer = new HumanPlayer(*_legal_move);
        std::cout << "Human player created" << std::endl;
        return humanPlayer;
    }

    Player* PlayerFactory::createRandom() {
        RandomPlayer* random_player = new RandomPlayer(*_legal_move);
        std::cout << "Random player created" << std::endl;
        return random_player;
    }

    Player* PlayerFactory::createMinMaxAB(const AIParameters &ai_parameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, ai_parameters.heuristic_parameters);
        int depth = ai_parameters.depth;

        MinMaxAb* alpha_beta = new MinMaxAb(*heuristic, *_legal_move, depth);
        std::cout << "AlphaBeta player created" << std::endl;
        return alpha_beta;
    }

    Player* PlayerFactory::createNegaMax(const AIParameters &ai_parameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, ai_parameters.heuristic_parameters);
        int depth = ai_parameters.depth;

        Negamax* negamax = new Negamax(*heuristic, *_legal_move, depth);
        std::cout << "NegaMax player created" << std::endl;
        return negamax;
    }

    Player* PlayerFactory::createNegaScout(const AIParameters &ai_parameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, ai_parameters.heuristic_parameters);
        int depth = ai_parameters.depth;

        class NegaScout* nega_scout = new class NegaScout(*heuristic, *_legal_move, depth);
        std::cout << "NegaScout player created" << std::endl;
        return nega_scout;
    }

    Player* PlayerFactory::createMTDF(const AIParameters &ai_parameters) {
        /*NegaScout* nega_scout = new NegaScout();
        return nega_scout;*/
        return nullptr;
    }

    Player* PlayerFactory::createMCTS(const AIParameters &ai_parameters) {
        /*NegaScout* nega_scout = new NegaScout();
        return nega_scout;*/
        return nullptr;
    }
}

