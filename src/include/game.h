//
// Pdp_chess university project
//

#ifndef PDP_CHESS_GAME_H
#define PDP_CHESS_GAME_H


#include "ai_player.h"
#include "board.h"
#include "bitboard_operations.h"
#include <vector>

namespace pdp_chess {

    class Game {
    public:
        Board board;

        Game();
        void drawBoard() const;
        void fromString(std::string string);
        void playMove(Move move);
        bool getPlayerRound(); // return true if next player to play is white

    private:
        AiPlayer* _white_player;
        AiPlayer* _black_player;
        AiPlayer* _players[2] = {_black_player, _white_player};
        color _current_color;
        std::vector<Move> _history;
    };

}

#endif //PDP_CHESS_GAME_H
