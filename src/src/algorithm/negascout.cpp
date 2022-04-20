#include "board.h"
#include "move.h"
#include "player/ai_player.h"
#include "negascout.h"
#include <algorithm>
#include <limits> 

namespace pdp_chess {

    Negascout::Negascout(Heuristic &heuristic, LegalMove &legal_move, int depth){
        _heuristic = &heuristic;
        _legal_move = &legal_move;
        _depth = depth;
    }


    Move Negascout::askNextMove(Board& board, color current_color){
        int i, score;
        i = 0;
        int alpha = std::numeric_limits<int>::min();
        int beta = std::numeric_limits<int>::max();
        Move best_move;
        std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
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
        board.doMove(best_move);
        std::cout << "Meilleur coup :" << _heuristic->evaluateBoard(board, current_color) << std::endl;
        board.undoMove();

        return best_move;
    }
    
    int Negascout::algoNegaScout(Board board, int depth, int alpha, int beta, bool current_color){
        if(depth==0 || board.isGameOver()){
            auto valueh = _heuristic->evaluateBoard(board, current_color);
            return valueh;
        }
        int i, score;
        i = 0;
        std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
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