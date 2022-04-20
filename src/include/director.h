//
// Pdp_chess university project
//

#ifndef PDP_CHESS_DIRECTOR_H
#define PDP_CHESS_DIRECTOR_H

#include <string>
#include "game.h"
#include "legal_move_v1.h"
#include "legal_move_v2.h"
#include "player_factory.h"
#include "parameters.h"

namespace pdp_chess {

    class Director{
    private:
        Game game;
        LegalMoveV1 legalMoveV1;
        LegalMoveV2 legalMoveV2;
        AiFactory aiFactory;

    public:
        Director();
        void LoadMatchFromJson(std::string filePath);
        void LoadMatchFromMatchParameters(MatchParameters matchParameters);
        void LoadBoard();
        void PlayMatch(bool is_timed);
        MatchParameters GetMatchParameters();
        void GetMatchRecap
    };

}

#endif //PDP_CHESS_DIRECTOR_H
