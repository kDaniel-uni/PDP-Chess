//
// Pdp_chess university project
//

#ifndef PDP_CHESS_BOARD_H
#define PDP_CHESS_BOARD_H

#include <string>
#include <array>
#include <vector>
#include "player_state.h"
#include "move.h"
#include "bitboard_operations.h"

namespace pdp_chess {

    class Board {
    public :
        std::vector<Move> history;
        PlayerState* pieces[2];

        Board();
        bool isDraw();
        std::string result();
        bool isGameOver();
        std::string toString() const;
        void fromString(const char *filename); //load a game wrote in the filename, if no filename, load the default game.
        void doMove(Move mv, bool is_main_loop = false);
        Move undoMove(bool is_main_loop = false);
        void resetToClassic();
        void resetToEmpty();
        void draw() const;


    private:
        int _moves_without_eating_counter;

        void updateWhiteAndBlackPieces();
        bool equal(const Board& board);
        Board clone();
    };

}

#endif //PDP_CHESS_BOARD_H