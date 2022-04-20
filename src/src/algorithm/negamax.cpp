//
// Pdp_chess university project
//

#include "board.h"
#include "move.h"
#include "player/ai_player.h"
#include "legal_move.h"
#include "heuristic.h"
#include "negamax.h"
#include "vector_shuffle.h"
#include <algorithm>
#include <limits>
#include <iostream>
#include <random>


namespace pdp_chess {

    Negamax::Negamax(Heuristic &heuristic, LegalMove &legal_move, int depth) : AIPlayer(legal_move, heuristic, depth){
    }

    Move Negamax::askNextMove(Board &board, color current_color){
        Move best_move;
        int value;
        int value_max = std::numeric_limits<int>::min();
        int alpha = std::numeric_limits<int>::min();
        int beta = std::numeric_limits<int>::max();

        std::vector<Move> legal_moves = _legal_move->GetLegalMoves(board, current_color);
        moveShuffle(legal_moves);

        for(Move move : legal_moves){
            board.doMove(move);
            value = -algoNegaMax(board, _depth-1, -beta, -alpha, !current_color);
            if ( value > value_max ){
                value_max = value;
                best_move = move;
            }
            board.undoMove();
            alpha = std::max(alpha, value_max);
            if (alpha >= beta){
                break;
            }
        }

        board.doMove(best_move);
        std::cout << "Meilleur coup :" << _heuristic->evaluateBoard(board, current_color) << std::endl;
        board.undoMove();

        return best_move;
    }

    int Negamax::algoNegaMax(Board &board, int depth, int alpha, int beta, bool current_color){
        int value;
        if(depth==0 || board.isGameOver()){
            value = _heuristic->evaluateBoard(board, current_color);
            return value;
        }

        std::vector<Move> legal_moves = _legal_move->GetLegalMoves(board, current_color);
        for(Move move : legal_moves){
            board.doMove(move);
            value = std::max(value, -algoNegaMax(board, depth-1, -beta, -alpha, !current_color));
            board.undoMove();
            alpha = std::max(alpha, value);
            if (alpha >= beta){
                return value;
            }
        }
        return value;
    }
}
