//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BOARD_H
#define PDP_ECHEC_BOARD_H
#include <string>
#include <array>
#include "bitboard_operations.h"

class board{
private :

public :
    board();
    std::string result();
    bool is_game_over();
    std::string to_string();
    void from_string(std::string filename); //load a game wrote in the filename, if no filename, load the default game.
    void update_white_and_black_pieces();
    Bitboards* _pieces[2];

};

#endif PDP_ECHEC_BOARD_H