//
// Pdp_chess university project
//

#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "game.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];
    Game g = Game();
    g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
    Move mv;

    if (arg == "1"){
        mv.start_position = 15;
        mv.start_type = 'P';
        mv.target_position = 31;
        g.playMove(mv);
        if (g.board.toString() == "RNBQKBNRPPPPPPP----------------P----------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    }else if( arg == "2"){
        mv.start_position = 1;
        mv.start_type = 'N';
        mv.target_position = 16;
        g.playMove(mv);
        if (g.board.toString() == "R-BQKBNRPPPPPPPPN-------------------------------pppppppprnbqkbnr"){
            return EXIT_SUCCESS;
        }

    }else if ( arg == "3"){
        g.fromString("---------------------------P------q-----------------------------");
        mv.start_position = 27;
        mv.start_type = 'P';
        mv.target_position = 34;
        g.playMove(mv);
        if (g.board.toString() != "----------------------------------P-----------------------------"){
            return EXIT_FAILURE;
        }
        mv.start_position = 34;
        mv.start_type = 'P';
        mv.target_position = 42;
        g.playMove(mv);
        if (g.board.toString() == "------------------------------------------P---------------------"){
            return EXIT_SUCCESS;
        }

    }else if ( arg == "4"){

        g.fromString("-----Q---------------------R-------------------------------q---r");
        g.board.draw();

        mv.start_position = 27;
        mv.start_type = 'R';
        mv.target_position = 59;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "-----Q-----------------------------------------------------R---r"){
            return EXIT_FAILURE;
        }
        mv.start_position = 63;
        mv.start_type = 'r';
        mv.target_position = 59;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "-----Q-----------------------------------------------------r----"){
            return EXIT_FAILURE;
        }
        mv.start_position = 5;
        mv.start_type = 'Q';
        mv.target_position = 3;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "---Q-------------------------------------------------------r----"){
            return EXIT_FAILURE;
        }
        mv.start_position= 59;
        mv.start_type = 'r';
        mv.target_position = 3;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() == "---r------------------------------------------------------------"){
            return EXIT_SUCCESS;
        }

    }else if ( arg == "5"){

        g.fromString("-----Q---------------------R-------------------------------q---r");
        g.board.draw();

        mv.start_position = 27;
        mv.start_type = 'R';
        mv.target_position = 59;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "-----Q-----------------------------------------------------R---r"){
            return EXIT_FAILURE;
        }
        mv.start_position = 63;
        mv.start_type = 'r';
        mv.target_position = 59;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "-----Q-----------------------------------------------------r----"){
            return EXIT_FAILURE;
        }
        mv.start_position = 5;
        mv.start_type = 'Q';
        mv.target_position = 3;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "---Q-------------------------------------------------------r----"){
            return EXIT_FAILURE;
        }
        mv.start_position= 59;
        mv.start_type = 'r';
        mv.target_position = 3;
        g.playMove(mv);
        g.draw();

        if (g.board.toString() != "---r------------------------------------------------------------"){
            return EXIT_FAILURE;
        }

        g.board.undoMove();
        g.draw();

        if (g.board.toString() != "---Q-------------------------------------------------------r----"){
            return EXIT_FAILURE;
        }

        g.board.undoMove();
        g.draw();

        if (g.board.toString() != "-----Q-----------------------------------------------------r----"){
            return EXIT_FAILURE;
        }

        g.board.undoMove();
        g.draw();

        if (g.board.toString() != "-----Q-----------------------------------------------------R---r"){
            return EXIT_FAILURE;
        }

        g.board.undoMove();
        g.draw();

        if (g.board.toString() == "-----Q---------------------R-------------------------------q---r"){
            return EXIT_SUCCESS;
        }

    }
    return EXIT_FAILURE;

}