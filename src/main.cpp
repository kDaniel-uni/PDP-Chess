#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "game.h"

int main(int argc, char *argv[])
{
    game* g = new game();
    g->drawBoard("rnbkqbnrpppppppp--------------------------------PPPPPPPPRNBQKBNR");
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}