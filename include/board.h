//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BOARD_H
#define PDP_ECHEC_BOARD_H
#include <string>
#include <array>
#include "bitboards.h"

class board{
private :
    Bitboards* _bitboards;
public :
    board();
    std::string result();
    bool is_game_over();
    char* to_string();
    void from_string(std::string filename); //load a game wrote in the filename, if no filename, load the default game.
    void upgrade_white_and_black_pieces();

};

#endif PDP_ECHEC_BOARD_H