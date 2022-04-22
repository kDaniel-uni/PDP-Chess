//
// Pdp_chess university project
//

#ifndef PDP_CHESS_DIRECTOR_H
#define PDP_CHESS_DIRECTOR_H

#include <string>
#include <chrono>
#include <fstream>
#include "engine/game.h"
#include "legal_move_v1.h"
#include "legal_move_v2.h"
#include "player_factory.h"
#include "match_parser.h"

namespace pdp_chess {

    class Director {
    private:
        Game *_game;
        LegalMoveV1 *_legal_move_v1;
        LegalMoveV2 *_legal_move_v2;
        PlayerFactory *_player_factory_v1;
        PlayerFactory *_player_factory_v2;
        MatchParameters _match_parameters;
        std::chrono::milliseconds _game_time;


    public:
        Director();

        bool loadMatchFromJson(std::string file_path, bool load_v1);

        void loadMatchFromMatchParameters(MatchParameters match_parameters, bool load_v1);

        void loadBoard(const std::string &board);

        void playMatch(bool is_timed);

        void resetGame();

        MatchParameters getRecapMatchParameters();

        void getMatchRecap();

        void setDraw(bool draw);
    };

}

#endif //PDP_CHESS_DIRECTOR_H
