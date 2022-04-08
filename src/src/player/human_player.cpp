//
// Pdp_chess university project
//

#include "human_player.h"
#include <iostream>

namespace pdp_chess {

    HumanPlayer::HumanPlayer() {
        legal_move = new Legalmove();
    }

    Move HumanPlayer::askNextMove(Board &board, bool current_color) {
        board.draw();
        auto moves = legal_move->legalMove(board, current_color);
        std::cout << "Choose a move to play : " << std::endl;
        return moves.front();
    }

}
