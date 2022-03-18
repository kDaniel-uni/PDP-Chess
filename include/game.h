
#ifndef PDP_ECHEC_GAME_H
#define PDP_ECHEC_GAME_H


#include "ai_player.h"
#include <vector>

class game {
public:
    void drawBoard(std::string);

private:
    ai_player* white_player;
    ai_player* black_player;
    ai_player* current_player;
    std::vector<move> history;
};


#endif //PDP_ECHEC_GAME_H
