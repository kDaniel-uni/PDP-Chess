#ifndef PDP_ECHEC_BOARD_H
#define PDP_ECHEC_BOARD_H
#include <string>
#include <array>

class board{
private :

public : 
    std::string result();
    bool is_game_over();
    std::string board_to_string();
    void load_game(std::string filename); //load a game wrote in the filename, if no filename, load the default game.
    void upgrade_white_and_black_pieces();

};

#endif PDP_ECHEC_BOARD_H