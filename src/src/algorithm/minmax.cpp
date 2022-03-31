//
// Pdp_echec university project
//

#include "board.h"
#include "move.h"
#include "ai_player.h"
#include <limits>

namespace pdp_chess {

    int minmax(Board board, int depth, AiPlayer ai_player){
        int value = 0;
        if(depth==0 || board.is_game_over()){
            //return valeurPlateau(board);
            return 0;
        }
        if(ai_player){
            int value_max = std::numeric_limits<int>::min;
            move[] legal_moves = board.generate_legal_moves();
            for(move move : legal_moves){
                board.push(move);
                value = minmax(board, depth-1, false);
                board.pop();
                if(value > value_max){
                    value_max = value;
                }
                return value;
            }
        }
        else{
            int value_min = std::numeric_limits<int>::max;
            move[] legal_moves = board.generate_legal_moves();
            for(move move : legal_moves){
                board.push(move);
                value = minmax(board,depth-1,true);
                board.pop();
                if value < value_min{
                    value_min = value;
                }
                return value;
            }
        }
    }

}

