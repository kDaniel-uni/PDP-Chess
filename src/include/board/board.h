//
// Pdp_chess university project
//

#ifndef PDP_CHESS_BOARD_H
#define PDP_CHESS_BOARD_H

#include <string>
#include <array>
#include <vector>
#include "bitboards.h"
#include "move.h"

namespace pdp_chess {

    class Board {
    public :
        int heuristic_board_value;
        Bitboards* _pieces[2];
        std::vector<Move> _history;

        Board();
        std::string result();
        bool isGameOver();
        std::string toString() const;
        void fromString(const char *filename); //load a game wrote in the filename, if no filename, load the default game.
        void updateWhiteAndBlackPieces();
        void doMove(Move mv);
        void undoMove();
        void resetToClassic();
        void resetToEmpty();
        int getColor(int index); // 1 if is white pieces, 0 if it's black pieces.
        char findType(uint8_t index) const;
    };

}

#endif //PDP_CHESS_BOARD_H