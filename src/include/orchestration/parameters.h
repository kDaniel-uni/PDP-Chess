//
// Pdp_chess university project
//

#ifndef PDP_CHESS_PARAMETERS_H
#define PDP_CHESS_PARAMETERS_H

#include <string>

namespace pdp_chess {

    enum HeuristicParameterType{
        Pawns,
        Rooks,
        Bishops,
        Knights,
        Queen,
        King,
        Backward,
        Forward,
        Doubled,
        Isolated,
        Legal,
        HeuristicNone
    };

    std::string GetStringFromHeuristicParameterType(HeuristicParameterType type);

    struct HeuristicParameters{
        int pawns_value = 20;
        int rooks_value = 100;
        int bishops_value = 60;
        int knights_value = 60;
        int queen_value = 180;
        int king_value = 4000;
        int backward_value = 10;
        int isolated_value = 10;
        int doubled_value = 10;
        int legal_move_value = 2;
        int forward_pawn_value = 1;

        void SetAllToZero();

        void ChangeValue(HeuristicParameterType type, int value);
    };

    struct AIParameters{
        int depth = 1;
        HeuristicParameters heuristicParameters;
    };

    enum PlayerType{
        Human,
        Random,
        AlphaBeta,
        NegaMax,
        NegaScout,
        Mtdf,
        Mcts,
        PlayerNone
    };

    std::string GetStringFromPlayerType(PlayerType type);

    struct PlayerParameters{
        PlayerType playerType;
        AIParameters aiParameters;
    };

    struct MatchParameters{
        PlayerParameters whitePlayerParameters;
        PlayerParameters blackPlayerParameters;
    };
}

#endif //PDP_CHESS_PARAMETERS_H
