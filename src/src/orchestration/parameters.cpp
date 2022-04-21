//
// Pdp_chess university project
//

#include "orchestration/parameters.h"

namespace pdp_chess {

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
            default : return "";
        }
    }

    std::string GetStringFromPlayerType(PlayerType type){
        switch (type) {
            case Human: return "Human";
            case Random: return "Random";
            case AlphaBeta: return "AlphaBeta";
            case NegaMax: return "NegaMax";
            case NegaScout: return "NegaScout";
            case Mtdf: return "Mtdf";
            case Mcts: return "Mcts";
            default : return "";
        }
    }

    void HeuristicParameters::ChangeValue(HeuristicParameterType type, int value) {
        switch (type) {
            case Pawns:
                pawns_value = value;
                break;
            case Rooks:
                rooks_value = value;
                break;
            case Bishops:
                bishops_value = value;
                break;
            case Knights:
                knights_value = value;
                break;
            case Queen:
                queen_value = value;
                break;
            case King:
                king_value = value;
                break;
            case Backward:
                backward_value = value;
                break;
            case Forward:
                forward_pawn_value = value;
                break;
            case Doubled:
                doubled_value = value;
                break;
            case Isolated:
                isolated_value = value;
                break;
            case Legal:
                legal_move_value = value;
                break;
            default : return;
        }
    }

    void HeuristicParameters::SetAllToZero() {
        pawns_value = 0;
        rooks_value = 0;
        bishops_value = 0;
        knights_value = 0;
        queen_value = 0;
        king_value = 0;
        backward_value = 0;
        isolated_value = 0;
        doubled_value = 0;
        legal_move_value = 0;
        forward_pawn_value = 0;
    }
}