//
// Pdp_echec university project
//

#include "../../include/game.h"
#include <string.h>

int main (int argc, char *argv[]) {
    game* g = new game();
    char* begin_boards = "PPPPpppp------------------------------------------------------Kk";
    g->_board->from_string(begin_boards);
    char* end_boards = g->_board->to_string();
    if (strcmp(begin_boards,end_boards) == 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

