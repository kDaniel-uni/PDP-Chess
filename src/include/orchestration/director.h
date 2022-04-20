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

    class Director{
    private:
        Game* _game;
        LegalMoveV1* _legalMoveV1;
        LegalMoveV2* _legalMoveV2;
        PlayerFactory* _playerFactoryV1;
        PlayerFactory* _playerFactoryV2;
        MatchParameters _matchParameters;
        std::chrono::milliseconds _gameTime;


    public:
        Director();
        bool LoadMatchFromJson(std::string file_path, bool load_v1);
        void LoadMatchFromMatchParameters(MatchParameters matchParameters, bool load_v1);
        void LoadBoard(const std::string &board);
        void PlayMatch(bool is_timed);
        void ResetGame();
        MatchParameters GetRecapMatchParameters();
        void GetMatchRecap();
    };

}

#endif //PDP_CHESS_DIRECTOR_H
