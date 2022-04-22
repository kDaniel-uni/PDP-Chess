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

    std::string getStringFromHeuristicParameterType(HeuristicParameterType type);

    struct HeuristicParameters{
        int pawns_value = 20;
        int rooks_value = 100;
        int bishops_value = 60;
        int knights_value = 60;
        int queen_value = 180;
        int king_value = 4000;
        int backward_value = 0;
        int isolated_value = 0;
        int doubled_value = 0;
        int legal_move_value = 2;
        int forward_pawn_value = 1;

        void setAllToZero();

        void changeValue(HeuristicParameterType type, int value);
    };

    struct AIParameters{
        int depth = 1;
        HeuristicParameters heuristic_parameters;
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

    std::string getStringFromPlayerType(PlayerType type);

    struct PlayerParameters{
        PlayerType player_type;
        AIParameters ai_parameters;
    };

    struct MatchParameters{
        PlayerParameters white_player_parameters;
        PlayerParameters black_player_parameters;
    };
}

#endif //PDP_CHESS_PARAMETERS_H
