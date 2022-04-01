#include "board.h"
#include "move.h"
#include "ai_player.h"
#include <algorithm>
#include <limits> 

namespace pdp_chess {
    class NegaMax : public AiPlayer{


        Move findNextMove(Board& board, color current_color){
            
        }

        std::string getParameters(){

        }

        int negaMax(Board board, int depth, bool ai_player_turn){
            int value = 0;
            if(depth==0 || board.isGameOver()){
                return Heuristic::evaluateBoard(board);
            }
            int value_max = stf::numeric_limits<int>::min();
            std::vector<Move> legal_moves = legal_moves(board, ai_player_turn);
            for(Move move : legal_moves){
                board.doMove(move);
                value = -negaMax(depth-1);
                board.undoMove(move);
                if(value > value_max){
                    value_max = value;
                }
            }
            return value_max;
        }
    };

}