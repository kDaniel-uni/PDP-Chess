//
// Pdp_chess university project
//

#include "human_player.h"
#include <iostream>

namespace pdp_chess {

    HumanPlayer::HumanPlayer(LegalMove &legal_move) : Player(legal_move) {
        initMoveMap();
    }

    Move HumanPlayer::askNextMove(Board &board, color current_color) {
        board.draw();
        std::cout << "List of legal move : " << std::endl;
        char input[5];
        Move m;
        bool valid_move = false;
        auto moves = _legal_move->getLegalMoves(board, current_color);
        // print of possible moves
        for (Move movement : moves) {
            std::cout << _move_map[movement.start_position] << _move_map[movement.target_position] << std::endl;
        }
        while (!valid_move) {
            std::cout << "Choose a move to play : " << std::endl;
            std::cin.getline(input, 5);


            m = moveFromString(input);
            for (Move mv : moves) {
                if ((m.start_position == mv.start_position) && (m.target_position == mv.target_position)) {
                    m.start_type = mv.start_type;
                    valid_move = true;
                    return m;
                }
            }
            std::cout << " it is not a valid move" << std::endl;
        }
        return m;
    }

    void HumanPlayer::initMoveMap() {
        char tmp = 'a';
        int index = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                _move_map[index] = std::string(tmp + std::to_string(x + 1));
                index++;
                tmp = (char) tmp + 1;
            }
            tmp = 'a';

        }
    }

    Move HumanPlayer::moveFromString(std::string string_move) {

        std::string start = string_move.substr(0, 2);
        std::string target = string_move.substr(2);

        Move move;
        for (int i = 0; i < 64; i++) {
            if (start == _move_map[i]) {
                move.start_position = i;
            }
            if (target == _move_map[i]) {
                move.target_position = i;
            }
        }
        return move;

    }

}
