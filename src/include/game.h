//
// Pdp_chess university project
//

#ifndef PDP_CHESS_GAME_H
#define PDP_CHESS_GAME_H


#include "player/ai_player.h"
#include "board.h"
#include "bitboard_operations.h"

namespace pdp_chess {

    class Game {
    public:
        Board board;

        Game();
        Game(Player* white_player, Player* black_player);
        void start();
        void playMove(Move move);
        void fromString(const std::string& string);

    private:
        Player* _players[2];
        color _current_color;

        void step();
    };

}

#endif //PDP_CHESS_GAME_H
