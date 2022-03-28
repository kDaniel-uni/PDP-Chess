//
// Pdp_echec university project
//

#include "board.h"
#include "move.h"
#include "ai_player.h"
#include <algorithm>
#include <limits> 

using namespace std;

int minmax_alphabeta(board board, int depth, int alpha, int beta, ai_player ai_player){
    int value = 0;
    if(depth==0 || board.is_game_over()){
        //return ValeurPlateau(board);
        return 0;
    }
    if(ai_player){
        int value_max = std::numeric_limits<int>::min();
        move[] legal_moves = board.generate_legal_moves();
        for (move move : legal_moves)
        {
            board.push(move);
            value = minmax_alphabeta(board, depth-1, alpha, beta, False);
            board.pop();
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
        move[] legal_moves = board.generate_legal_moves();
        for (move move : legal_moves)
        {
            board.push(move);
            value = minmax_alphabeta(board, depth-1, alpha, beta, True);
            board.pop();
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