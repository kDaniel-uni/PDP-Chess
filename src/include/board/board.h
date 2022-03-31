//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BOARD_H
#define PDP_ECHEC_BOARD_H

#include <string>
#include <array>
#include "bitboards.h"
#include "move.h"
#include "heuristic.h"

namespace pdp_chess {

    class Board {
    public :
        int heuristic_board_value;
        Bitboards* _pieces[2];

        Board();
        std::string result();
        bool isGameOver();
        std::string toString() const;
        void fromString(const char *filename); //load a game wrote in the filename, if no filename, load the default game.
        void updateWhiteAndBlackPieces();
        void moving(Move mv);
        int getBoardValue(bool white_black_turn, Heuristic *h); //true for white, false for black
        void resetToClassic();
        void resetToEmpty();
        int getColor(int index); // 1 if is white pieces, 0 if it's black pieces.
    };

}

#endif //PDP_ECHEC_BOARD_H