//
// Pdp_chess university project
//


#include <algorithm>
#include <limits>
#include <iostream>

#include "minmax_ab.h"

namespace pdp_chess {

    MinMaxAb::MinMaxAb(Heuristic &heuristic, LegalMove &legal_move, int depth) : AIPlayer(legal_move, heuristic, depth){
    }

    Move MinMaxAb::askNextMove(Board &board, color current_color) {

        Move best_move;
        int value;
        int alpha = std::numeric_limits<int>::min();
        int beta = std::numeric_limits<int>::max();

        std::vector<Move> legal_moves = _legal_move->getLegalMoves(board, current_color);
        moveShuffle(legal_moves);

        for (Move move : legal_moves) {
            board.doMove(move);
            value = betaAlpha(board, _depth - 1, alpha, beta, !current_color, current_color);
            board.undoMove();

            if (value > alpha) {
                alpha = value;
                best_move = move;
            }
        }

        board.doMove(best_move);
        std::cout << "Meilleur coup : " << _heuristic->evaluateBoard(board, current_color) << std::endl;
        board.undoMove();

        return best_move;
    }

    int MinMaxAb::betaAlpha(Board board, int depth, int alpha, int beta, bool current_color, bool base_color) {

        if (depth == 0 || board.isGameOver()) {
            auto value = _heuristic->evaluateBoard(board, base_color);
            return value;
        }

        std::vector<Move> legal_moves = _legal_move->getLegalMoves(board, current_color);
        for (Move move : legal_moves) {
            board.doMove(move);
            beta = std::min(beta, alphaBeta(board, depth - 1, alpha, beta, !current_color, base_color));
            board.undoMove();

            if (alpha >= beta) {
                return alpha;
            }
        }
        return beta;
    }

    int MinMaxAb::alphaBeta(Board board, int depth, int alpha, int beta, bool current_color, bool base_color) {
        if (depth == 0 || board.isGameOver()) {
            auto value = _heuristic->evaluateBoard(board, base_color);
            return value;
        }

        std::vector<Move> legal_moves = _legal_move->getLegalMoves(board, current_color);
        for (Move move : legal_moves) {
            board.doMove(move);
            alpha = std::max(alpha, betaAlpha(board, depth - 1, alpha, beta, !current_color, base_color));
            board.undoMove();

            if (alpha >= beta) {
                return beta;
            }
        }
        return alpha;
    }
}