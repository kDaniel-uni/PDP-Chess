//
// Pdp_chess university project
//

#include "game.h"
#include "minmax_ab.h"


using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];

    if (arg == "1"){
        Heuristic heuristic = Heuristic();
        LegalMove legal_move = LegalMove();
        MinMaxAb* white_player = new MinMaxAb(heuristic, legal_move, 2);
        MinMaxAb* black_player = new MinMaxAb(heuristic, legal_move, 2);
        Game g = Game(white_player,black_player);
        g.fromString("----------------K---------------------------k-------------------");
        g.start();
        if (strcmp(g.board.result().c_str(),"No winner") == 0){
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    }

    else if (arg == "2"){
        Heuristic heuristic = Heuristic();
        LegalMove legal_move = LegalMove();
        Game g = Game();
        g.board.resetToClassic();
        Move mv1;
        mv1.start_position = 1;
        mv1.start_type = 'N';
        mv1.target_position = 18;
        Move mv2;
        mv2.start_position = 57;
        mv2.start_type = 'n';
        mv2.target_position = 42;
        Move mv3;
        mv3.start_position = 18;
        mv3.start_type = 'N';
        mv3.target_position = 1;
        Move mv4;
        mv4.start_position = 42;
        mv4.start_type = 'n';
        mv4.target_position = 57;
        g.board.doMove(mv1);
        g.board.doMove(mv2);
        g.board.doMove(mv3);
        g.board.doMove(mv4);
        if(g.board.isGameOver() && (strcmp(g.board.result().c_str(),"No winner") == 0)){
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    }
}