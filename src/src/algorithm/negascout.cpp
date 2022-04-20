//
// Pdp_chess university project
//

#include "negascout.h"
#include <limits>

namespace pdp_chess {

    NegaScout::NegaScout(Heuristic &heuristic, LegalMove &legal_move, int depth) : AIPlayer(legal_move, heuristic, depth){
    }

    /*Move NegaScout::askNextMove(Board& board, color current_color){
        return
    }*/

    int NegaScout::algoNegaScout(Board board, int depth, int alpha, int beta, bool current_color, bool base_color){
        int value_current = 0;
        if(depth==0 || board.isGameOver()){
            auto valueh = _heuristic->evaluateBoard(board, current_color);
            return valueh;
        }
        int score = std::numeric_limits<int>::min();
        int n = beta;

        std::vector<Move> legal_moves = _legal_move->GetLegalMoves(board, current_color);

        for(Move move : legal_moves){
            board.doMove(move);
            int value_current = -algoNegaScout(board, depth-1, n, -alpha, !current_color, current_color);
            if(value_current > score){
                if(n=beta || depth<=2){
                    score = value_current;
                }
                else{
                    score = -algoNegaScout(board, depth-1, -beta, -value_current, !current_color, current_color);
                }
            }
            if(score > alpha){
                alpha = score;
            }
            board.undoMove();
            if(alpha >=beta){
                return alpha;
            }
            n = alpha+1;
        }
        return score;
    }
}