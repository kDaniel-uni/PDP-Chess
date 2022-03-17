//
// Created by KAAAAAAAAAAAAAAAAARL on 17/03/2022.
//

#ifndef PDP_ECHEC_AI_PLAYER_H
#define PDP_ECHEC_AI_PLAYER_H


#include <xstring>
#include "move.h"

class ai_player {
public :
    virtual ~ai_player() {}
    virtual move find_next_move() = 0;
    virtual std::string get_parameters() = 0;

};


#endif //PDP_ECHEC_AI_PLAYER_H
