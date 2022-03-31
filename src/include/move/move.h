//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MOVE_H
#define PDP_CHESS_MOVE_H

#include "bitboards.h"

namespace pdp_chess {

    struct Move{
        uint8_t start_position;
        char start_type;
        uint8_t target_position;
        char target_type;
    };

}

#endif //PDP_CHESS_MOVE_H
