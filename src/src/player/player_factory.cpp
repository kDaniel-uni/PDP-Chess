//
// Pdp_chess university project
//

#include "player_factory.h"

namespace pdp_chess {

    PlayerFactory::PlayerFactory(LegalMove &legal_move) {
        _legal_move = &legal_move;
    }

    Player* pdp_chess::PlayerFactory::createPlayer(const PlayerParameters &playerParameters) {
        PlayerType playerType = playerParameters.playerType;

        switch (playerType) {
            case Human: return createHumanPlayer();
            case Random: return createRandom();
            case AlphaBeta: return createMinMaxAB(playerParameters.aiParameters);
            case NegaMax: return createNegaMax(playerParameters.aiParameters);
            case NegaScout: return createNegaScout(playerParameters.aiParameters);
            case Mtdf: return createMTDF(playerParameters.aiParameters);
            case Mcts: return createMCTS(playerParameters.aiParameters);
            default: return createRandom();
        }
    }

    Player* PlayerFactory::createHumanPlayer() {
        HumanPlayer* humanPlayer = new HumanPlayer(*_legal_move);
        return humanPlayer;
    }

    Player* PlayerFactory::createRandom() {
        RandomPlayer* random_player = new RandomPlayer(*_legal_move);
        return random_player;
    }

    Player* PlayerFactory::createMinMaxAB(const AIParameters &aiParameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, aiParameters.heuristicParameters);
        int depth = aiParameters.depth;

        MinMaxAb* alpha_beta = new MinMaxAb(*heuristic, *_legal_move, depth);
        return alpha_beta;
    }

    Player* PlayerFactory::createNegaMax(const AIParameters &aiParameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, aiParameters.heuristicParameters);
        int depth = aiParameters.depth;

        Negamax* negamax = new Negamax(*heuristic, *_legal_move, depth);
        return negamax;
    }

    Player* PlayerFactory::createNegaScout(const AIParameters &aiParameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, aiParameters.heuristicParameters);
        int depth = aiParameters.depth;

        class NegaScout* nega_scout = new class NegaScout(*heuristic, *_legal_move, depth);
        return nega_scout;
    }

    Player* PlayerFactory::createMTDF(const AIParameters &aiParameters) {
        /*NegaScout* nega_scout = new NegaScout();
        return nega_scout;*/
        return nullptr;
    }

    Player* PlayerFactory::createMCTS(const AIParameters &aiParameters) {
        /*NegaScout* nega_scout = new NegaScout();
        return nega_scout;*/
        return nullptr;
    }
}

