//
// Pdp_chess university project
//

#include "board.h"
#include "move.h"
#include "ai_player.h"
#include "legal_move.h"
#include <algorithm>
#include <limits> 

namespace pdp_chess {
    class MinMax_ab : public AiPlayer{



        Move findNextMove(Board& board, color current_color){
            
        }

        std::string getParameters(){

        }




        int minmax_alphabeta(Board board, int depth, int alpha, int beta, bool ai_player_turn){
            int value = 0;
            if(depth==0 || board.isGameOver()){
                return Heuristic::evaluateBoard(board);
            }
            if(ai_player_turn){
                int value_max = std::numeric_limits<int>::min();
                std::vector<Move> legal_moves = legal_move(board,ai_player_turn);
                for (Move move : legal_moves)
                {
                    board.doMove(move);
                    value = minmax_alphabeta(board, depth-1, alpha, beta, !ai_player_turn);
                    board.undoMove();
                    if(value > value_max){
                        value_max = value;
                    }
                    alpha = std::max(alpha, value);
                    if(beta<=alpha){
                        break;
                    }
                    return value;
                }
            }
            else{
                int value_min = std::numeric_limits<int>::max();
                std::vector<Move> legal_moves = legal_move(board,ai_player_turn);
                for (Move move : legal_moves)
                {
                    board.doMove(move);
                    value = minmax_alphabeta(board, depth-1, alpha, beta, !ai_player_turn);
                    board.undoMove();
                    if(value < value_min){
                        value_min = value;
                    }
                    beta = std::min({beta, value});
                    if(beta<=alpha){
                        break;
                    }
                    return value;
                }
            }
        }
    };

}