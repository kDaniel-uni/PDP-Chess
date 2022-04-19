//
// Pdp_chess university project
//

#include "random_player.h"

namespace pdp_chess {

    RandomPlayer::RandomPlayer(LegalMove& legal_move) {
        _legal_move = &legal_move;
    }

    Move RandomPlayer::askNextMove(Board &board, color current_color) {
        auto moves = _legal_move->GetLegalMoves(board, current_color);
        int random_pos = rand() % moves.size();
        return moves.at(random_pos);
    }

}