//
// Pdp_chess university project
//

#include "board.h"
#include "move.h"
#include "player/ai_player.h"
#include "legal_move.h"
#include "heuristic.h"
#include "minmax_ab.h"
#include <algorithm>
#include <limits>

namespace pdp_chess {

    MinMaxAb::MinMaxAb(Heuristic& heuristic, LegalMove& legal_move, int depth) {
        _heuristic = &heuristic;
        _legal_move = &legal_move;
        _depth = depth;
    }

    Move MinMaxAb::askNextMove(Board& board, color current_color){
            Move best_move;
            int value = 0;
            int alpha = std::numeric_limits<int>::min();
            int beta = std::numeric_limits<int>::max();
            if(current_color){
                int value_max = std::numeric_limits<int>::min();
                std::vector<Move> legal_moves = _legal_move->legalMove(board,current_color);
                for (Move move : legal_moves){
                    board.doMove(move);
                    printf("first move %f\n", _heuristic->evaluateBoard(board, current_color) );
                    value = minmax_alphabeta(board, _depth-1, alpha, beta, !current_color);
                    board.undoMove();
                    if(value > value_max){
                        value_max = value;
                        best_move = move;
                    }
                    alpha = std::max(alpha, value);
                    if(beta<=alpha){
                        break;
                    }
                }
            }
            else{
                int value_min = std::numeric_limits<int>::max();
                std::vector<Move> legal_moves = _legal_move->legalMove(board,current_color);
                for (Move move : legal_moves){
                    board.doMove(move);
                    value = minmax_alphabeta(board, _depth-1, alpha, beta, !current_color);
                    board.undoMove();
                    if(value < value_min){
                        value_min = value;
                        best_move = move;
                    }
                    beta = std::min(beta, value);
                    if(beta<=alpha){
                        break;
                    }
                }
            }
            return best_move;
        }

    int MinMaxAb::minmax_alphabeta(Board board, int depth, int alpha, int beta, bool ai_player_turn){
        int value = 0;
        if(depth==0 || board.isGameOver()){
            return _heuristic->evaluateBoard(board, ai_player_turn);
        }
        if(ai_player_turn){
            int value_max = std::numeric_limits<int>::min();
            std::vector<Move> legal_moves = _legal_move->legalMove(board,ai_player_turn);
            for (Move move : legal_moves){
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
            }
            return value_max;
        }
        else{
            int value_min = std::numeric_limits<int>::max();
            std::vector<Move> legal_moves = _legal_move->legalMove(board,ai_player_turn);
            for (Move move : legal_moves){
                board.doMove(move);
                value = minmax_alphabeta(board, depth-1, alpha, beta, !ai_player_turn);
                board.undoMove();
                if(value < value_min){
                    value_min = value;
                }
                beta = std::min(beta, value);
                if(beta<=alpha){
                    break;
                }
            }
            return value_min;
        }
    }

}