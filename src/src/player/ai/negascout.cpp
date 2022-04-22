//
// Pdp_chess university project
//

#include "board.h"
#include "move.h"
#include "player/ai_player.h"
#include "negascout.h"
#include "vector_shuffle.h"
#include <algorithm>
#include <limits>
#include <iostream>

namespace pdp_chess {

    NegaScout::NegaScout(Heuristic &heuristic, LegalMove &legal_move, int depth) : AIPlayer(legal_move, heuristic, depth){
    }


    Move NegaScout::askNextMove(Board& board, color current_color){
        int i, score;
        i = 0;
        int alpha = -std::numeric_limits<int>::max();
        int beta = std::numeric_limits<int>::max();
        Move best_move;
        std::vector<Move> legal_moves = _legal_move->getLegalMoves(board, current_color);
        moveShuffle(legal_moves);

        for(Move move : legal_moves){
            board.doMove(move);
            score = -algoNegaScout(board, _depth - 1, -alpha - 1, -alpha, !current_color);
            if( ( alpha < score ) && ( score < beta ) ){
                score = -algoNegaScout(board, _depth - 1, -beta, -score, !current_color);
            }
            if ( score > alpha ){
                alpha = score;
                best_move = move;
            }
            if( alpha >= beta){
                board.undoMove();
                break;
            }
            i++;
            board.undoMove();
        }

        /*board.doMove(best_move);
        std::cout << "Meilleur coup :" << _heuristic->evaluateBoard(board, current_color) << std::endl;
        board.undoMove();*/

        return best_move;
    }
    
    int NegaScout::algoNegaScout(Board& board, int depth, int alpha, int beta, bool current_color){
        if(depth==0 || board.isGameOver()){
            int valueh = _heuristic->evaluateBoard(board, current_color);
            return valueh;
        }
        int i, score;
        i = 0;
        std::vector<Move> legal_moves = _legal_move->getLegalMoves(board, current_color);
        for(Move move : legal_moves){
            board.doMove(move);
            score = -algoNegaScout(board, depth - 1, -alpha - 1, -alpha, !current_color);
            if( ( alpha < score ) && ( score < beta ) ){
                score = -algoNegaScout(board, depth - 1, -beta, -score, !current_color);
            }
            alpha = std::max(alpha, score);
            if( alpha >= beta){
                board.undoMove();
                break;
            }
            i++;
            board.undoMove();
        }
        return alpha;
    }

}