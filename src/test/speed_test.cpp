//
// Pdp_chess university project
//

#include "engine/game.h"
#include "legal_move_v2.h"
#include "legal_move_v1.h"
#include <chrono>
#include <vector>

using namespace pdp_chess;

int main(int argc, char *argv[]) {

    /*if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;*/

    Game game = Game();
    LegalMoveV1 legal_moves_v1 = LegalMoveV1();
    LegalMoveV2 legal_moves_v2 = LegalMoveV2();
    std::vector<Move> holder;

    auto t1 = std::chrono::high_resolution_clock::now();

    game.board.fromString("RNBQKBNR-------P---------------------------------------prnbqkbnr");
    for (int i = 0; i < 1000000; i++) {
        legal_moves_v1.getLegalMoves(game.board, true);
        legal_moves_v1.getLegalMoves(game.board, false);
    }

    game.board.fromString("-----P-Q--------------------q----------p------------------------");
    for (int i = 0; i < 1000000; i++) {
        legal_moves_v1.getLegalMoves(game.board, true);
        legal_moves_v1.getLegalMoves(game.board, false);
    }

    game.board.fromString("----------------KB--------------------------k-------------------");
    for (int i = 0; i < 1000000; i++) {
        legal_moves_v1.getLegalMoves(game.board, true);
        legal_moves_v1.getLegalMoves(game.board, false);
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "Execution time V1 : " << duration.count() << " ms" << std::endl;


    auto t1_v2 = std::chrono::high_resolution_clock::now();

    game.board.fromString("RNBQKBNR-------P---------------------------------------prnbqkbnr");
    for (int i = 0; i < 1000000; i++) {
        legal_moves_v2.getLegalMoves(game.board, true);
        legal_moves_v2.getLegalMoves(game.board, false);
    }

    game.board.fromString("-----P-Q--------------------q----------p------------------------");
    for (int i = 0; i < 1000000; i++) {
        legal_moves_v2.getLegalMoves(game.board, true);
        legal_moves_v2.getLegalMoves(game.board, false);
    }

    game.board.fromString("----------------KB--------------------------k-------------------");
    for (int i = 0; i < 1000000; i++) {
        legal_moves_v2.getLegalMoves(game.board, true);
        legal_moves_v2.getLegalMoves(game.board, false);
    }

    auto t2_v2 = std::chrono::high_resolution_clock::now();
    auto duration_v2 = duration_cast<std::chrono::milliseconds>(t2_v2 - t1_v2);
    std::cout << "Execution time V2 : " << duration_v2.count() << " ms" << std::endl;


}