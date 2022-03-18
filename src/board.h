#ifndef PDP_ECHEC_BOARD_H
#define PDP_ECHEC_BOARD_H
#include <string>
#include <array>
using namespace std;

class board{
private :

public : 
    std::string result();
    bool is_game_over();
    std::string board_to_string();
    void load_game(string filename); //load a game wrote in the filename, if no filename, load the default game.
};




#endif PDP_ECHEC_BOARD_H