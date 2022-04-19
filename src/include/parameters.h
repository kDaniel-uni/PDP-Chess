//
// Pdp_chess university project
//

#ifndef PDP_CHESS_GAME_PARAMETERS_H
#define PDP_CHESS_GAME_PARAMETERS_H

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

    std::string GetStringFromHeuristicParameterType(HeuristicParameterType type){
        switch (type) {
            case Pawns: return "Pawns";
            case Rooks: return "Rooks";
            case Bishops: return "Bishops";
            case Knights: return "Knights";
            case Queen: return "Queen";
            case King: return "King";
            case Backward: return "Backward";
            case Forward: return "Forward";
            case Doubled: return "Doubled";
            case Isolated: return "Isolated";
            case Legal: return "Legal";
            case HeuristicNone: return "";
        }
    }

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

        void ChangeValue(HeuristicParameterType type, int value){
            switch (type) {
                case Pawns: pawns_value = value;
                case Rooks: rooks_value = value;
                case Bishops: bishops_value = value;
                case Knights: knights_value = value;
                case Queen: queen_value = value;
                case King: king_value = value;
                case Backward: backward_value = value;
                case Forward: forward_pawn_value = value;
                case Doubled: doubled_value = value;
                case Isolated: isolated_value = value;
                case Legal: legal_move_value = value;
                case HeuristicNone: return;
            }
        }
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
        Negascout,
        Mtdf,
        Mcts,
        PlayerNone
    };

    std::string GetStringFromPlayerType(PlayerType type){
        switch (type) {
            case Human: return "Human";
            case Random: return "Random";
            case AlphaBeta: return "AlphaBeta";
            case NegaMax: return "NegaMax";
            case Negascout: return "Negascout";
            case Mtdf: return "Mtdf";
            case Mcts: return "Mcts";
            case PlayerNone: return "";
        }
    }

    struct PlayerParameters{
        PlayerType playerType;
        AIParameters aiParameters;
    };

    struct MatchParameters{
        PlayerParameters whitePlayerParameters;
        PlayerParameters blackPlayerParameters;
    };
}

#endif //PDP_CHESS_GAME_PARAMETERS_H
