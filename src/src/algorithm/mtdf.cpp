//
// Pdp_chess university project
//

#include "mtdf.h"

namespace pdp_chess {

    /*MTDF::MTDF(Heuristic &heuristic, LegalMove &legalMove, int depth) : AIPlayer(legalMove, heuristic, depth){

    }

    Move MTDF::findNextMove(Board &board, color current_color) {

    }

    std::string MTDF::getParameters() {

    }

    int MTDF::algoMTDF(Board board, int f, int depth, bool current_color, bool base_color) {
        int value = f;
        int beta = 0;
        int upperBound = std::numeric_limits<int>::max();
        int lowerBound = std::numeric_limits<int>::min();
        while (lowerBound < upperBound) {
            if (value = lowerBound) {
                beta = g + 1;
            } else {
                beta = value;
            }
            //value = AlphaBetaWithMemory(board, beta-1, beta, depth);
            if (value < beta) {
                upperBound = value;
            } else {
                lowerBound = value;
            }
        }
        return value;
    }*/

}