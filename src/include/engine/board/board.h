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
        int moves_without_eating_counter;
        PlayerState* _pieces[2];
        std::vector<Move> _history;

        Board();
        bool isDraw();
        std::string result();
        bool isGameOver();
        std::string toString() const;
        void fromString(const char *filename); //load a game wrote in the filename, if no filename, load the default game.
        void updateWhiteAndBlackPieces();
        void doMove(Move mv, bool is_main_loop = false);
        Move undoMove(bool is_main_loop = false);
        void resetToClassic();
        void resetToEmpty();
        int getColor(int index); // 1 if is white pieces, 0 if it's black pieces.
        char findType(uint8_t index) const;
        void draw() const;
        Board clone();
        bool equal(Board& board);
    };

}

#endif //PDP_CHESS_BOARD_H