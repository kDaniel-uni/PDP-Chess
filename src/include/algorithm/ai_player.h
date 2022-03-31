//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_AI_PLAYER_H
#define PDP_ECHEC_AI_PLAYER_H

#include <string>
#include "move.h"

namespace pdp_chess {

    class AiPlayer {
    public :
        virtual ~AiPlayer() {}
        virtual Move findNextMove() = 0;
    virtual std::string getParameters() = 0;

    };

}

#endif //PDP_ECHEC_AI_PLAYER_H
