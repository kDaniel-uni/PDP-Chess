//
// Pdp_chess university project
//

#include "negascout.h"

namespace pdp_chess {


        Move findNextMove(Board& board, color current_color){
            
        }

        std::string getParameters(){

        }

        int NegaScout(Board board, int depth, int alpha, int beta, boolean ai_player_turn){
            if(depth == 0 || board.isGameOver()){
                return Heuristic::evaluateBoard(board);
            }
            int value = std::numeric_limits<int>::min();
            int return_value = beta;
            std::vector<Move> legal_moves = legal_moves(board, ai_player_turn);
            for(Move move : legal_moves){
                board.doMove(move);
                int current_value = -NegaScout(board, depth-1, -n, -alpha);
                if(current_value > value){
                    if(return_value=beta || d<=2){
                        value = current_value;
                        }
                    else{
                        value = -NegaScout(board, depth-1, -beta, -current_value);
                        }
                    }
                    if(value > alpha){
                        alpha = value;
                        board.undoMove(move);
                    }
                    if(alpha >= beta){
                        return alpha;
                        n = alpha +1;
                    }
                }
                return value;
            }
    };

}