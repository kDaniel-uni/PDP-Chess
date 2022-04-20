//
// Pdp_chess university project
//

#include "player_factory.h"
#include <string>
#include <iostream>

namespace pdp_chess {

    PlayerFactory::PlayerFactory(LegalMove &legal_move) {
        _legal_move = &legal_move;
    }

    Player &pdp_chess::PlayerFactory::CreatePlayer(const PlayerParameters &playerParameters) {
        PlayerType playerType = playerParameters.playerType;

        switch (playerType) {
            case Human: return CreateHumanPlayer();
            case Random: return CreateRandom();
            case AlphaBeta: return CreateMinMaxAB(playerParameters.aiParameters);
            case NegaMax: return CreateNegaMax(playerParameters.aiParameters);
            case Negascout: return CreateNegaScout(playerParameters.aiParameters);
            case Mtdf: return CreateMTDF(playerParameters.aiParameters);
            case Mcts: return CreateMCTS(playerParameters.aiParameters);
            default: return CreateRandom();
        }
    }

    HumanPlayer &PlayerFactory::CreateHumanPlayer() {
        HumanPlayer* humanPlayer = new HumanPlayer(*_legal_move);
        return *humanPlayer;
    }

    RandomPlayer &PlayerFactory::CreateRandom() {
        RandomPlayer* random_player = new RandomPlayer(*_legal_move);
        return *random_player;
    }

    MinMaxAb &PlayerFactory::CreateMinMaxAB(const AIParameters &aiParameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, aiParameters.heuristicParameters);
        int depth = aiParameters.depth;

        MinMaxAb* alpha_beta = new MinMaxAb(*heuristic, *_legal_move, depth);
        return *alpha_beta;
    }

    Negamax &PlayerFactory::CreateNegaMax(const AIParameters &aiParameters) {
        Heuristic* heuristic = new Heuristic(*_legal_move, aiParameters.heuristicParameters);
        int depth = aiParameters.depth;

        Negamax* negamax = new Negamax(*heuristic, *_legal_move, depth);
        return *negamax;
    }

    NegaScout &PlayerFactory::CreateNegaScout(const AIParameters &aiParameters) {
        return ;
    }

    MTDF &PlayerFactory::CreateMTDF(const AIParameters &aiParameters) {
        return <#initializer#>;
    }

    MCTS &PlayerFactory::CreateMCTS(const AIParameters &aiParameters) {
        return <#initializer#>;
    }
}

