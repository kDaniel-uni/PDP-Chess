//
// Pdp_chess university project
//

#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "game.h"
#include "legal_move.h"
#include "legal_move_v2.h"
#include <iostream>
#include <chrono>

using namespace pdp_chess;

bool checkMoveInBasicLegalMoves(const Move &move) {
    switch (move.start_position) {
        case a2:
            if (move.target_position == a3 || move.target_position == a4) {
                return true;
            }
        case b2:
            if (move.target_position == b3 || move.target_position == b4) {
                return true;
            }
        case c2:
            if (move.target_position == c3 || move.target_position == c4) {
                return true;
            }
        case d2:
            if (move.target_position == d3 || move.target_position == d4) {
                return true;
            }
        case e2:
            if (move.target_position == e3 || move.target_position == e4) {
                return true;
            }
        case f2:
            if (move.target_position == f3 || move.target_position == f4) {
                return true;
            }
        case g2:
            if (move.target_position == g3 || move.target_position == g4) {
                return true;
            }
        case h2:
            if (move.target_position == h3 || move.target_position == h4) {
                return true;
            }
        case b1:
            if (move.target_position == a3 || move.target_position == c3) {
                return true;
            }
        case g1:
            if (move.target_position == f3 || move.target_position == h3) {
                return true;
            }
        default :
            return false;
    }
}

bool testPawn(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("--------P--------p----------------------------------------------");
    game.board.draw();

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 3) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != a2) {
            return false;
        } else {
            if (m.target_position != a4 && m.target_position != a3 && m.target_position != b3) {
                return false;
            }
        }
    }

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, false);
    } else {
        to_test = legalmove.legalMove(game.board, false);
    }

    if (to_test.size() != 2) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != b3) {
            return false;
        } else {
            if (m.target_position != b2 && m.target_position != a2) {
                return false;
            }
        }
    }
    return true;
}

bool testRooks(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("R---------------r-----------------------------------------------");
    game.board.draw();

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 9) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != a1) {
            return false;
        } else if (m.target_position != a2 && m.target_position != a3 && m.target_position != b1 &&
                   m.target_position != c1 && m.target_position != d1 && m.target_position != e1 &&
                   m.target_position != f1 && m.target_position != g1 && m.target_position != h1) {
            return false;
        }
    }

    return true;
}

bool testBishops(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("---------B--------------------------b---------------------------");
    game.board.draw();

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 6) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != b2) {
            return false;
        } else if (m.target_position != a1 && m.target_position != a3 && m.target_position != c1 &&
                   m.target_position != c3 && m.target_position != d4 && m.target_position != e5) {
            return false;
        }
    }

    return true;
}

bool testKnights(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("P----------n-----N----------------------------------------------");
    game.board.draw();


    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 6) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != b3 && m.start_position != a1) {
            return false;
        } else if (m.target_position != c1 && m.target_position != d2 && m.target_position != d4 &&
                   m.target_position != a5 && m.target_position != c5 && m.target_position != a2) {
            return false;
        }
    }

    return true;
}

bool testQueen(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("-----P-Q--------------------q----------p------------------------");
    game.board.draw();

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 9) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != h1 && m.start_position != f1) {
            return false;
        } else if (m.target_position != g1 && m.target_position != g2 && m.target_position != f3 &&
                   m.target_position != e4 && m.target_position != h2 && m.target_position != h3 &&
                   m.target_position != h4 && m.target_position != h5 && m.target_position != f2) {
            return false;
        }
    }

    return true;
}

bool testKing(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("K-------p------p------------------------------------------------");
    game.board.draw();

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 3) {
        return false;
    }

    for (Move m : to_test) {
        if (m.start_position != a1) {
            return false;
        } else if (m.target_position != b1 && m.target_position != a2 && m.target_position != b2) {
            return false;
        }
    }

    return true;
}

bool testBasic(Game &game, bool is_v1, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
    game.board.draw();

    if (is_v1) {
        to_test = pdp_chess::legal_move(game.board, true);
    } else {
        to_test = legalmove.legalMove(game.board, true);
    }

    if (to_test.size() != 20) {
        return false;
    }

    for (Move m : to_test) {
        if (!checkMoveInBasicLegalMoves(m)) {
            return false;
        }
    }

    return true;
}


int main(int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];
    Game g = Game();
    LegalMove legal_moves = LegalMove();

    if (arg == "1") {
        return !testPawn(g, true, legal_moves);

    } else if (arg == "2") {
        return !testPawn(g, false, legal_moves);

    } else if (arg == "3") {
        return !testRooks(g, true, legal_moves);

    } else if (arg == "4") {
        return !testRooks(g, false, legal_moves);

    } else if (arg == "5") {
        return !testBishops(g, true, legal_moves);

    } else if (arg == "6") {
        return !testBishops(g, false, legal_moves);

    } else if (arg == "7") {
        return !testKnights(g, true, legal_moves);

    } else if (arg == "8") {
        return !testKnights(g, false, legal_moves);

    } else if (arg == "9") {
        return !testQueen(g, true, legal_moves);

    } else if (arg == "10") {
        return !testQueen(g, false, legal_moves);

    } else if (arg == "11") {
        return !testKing(g, true, legal_moves);

    } else if (arg == "12") {
        return !testKing(g, false, legal_moves);

    } else if (arg == "13") {
        return !testBasic(g, true, legal_moves);

    } else if (arg == "14") {
        return !testBasic(g, false, legal_moves);

    } else if (arg == "15") {
        auto t1 = std::chrono::high_resolution_clock::now();

        for (int index = 0; index < 10000; index++){
            testPawn(g, true, legal_moves);
            testRooks(g, true, legal_moves);
            testBishops(g, true, legal_moves);
            testKnights(g, true, legal_moves);
            testQueen(g, true, legal_moves);
            testKing(g, true, legal_moves);
            testBasic(g, true, legal_moves);
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << duration.count() << " ms" << std::endl;
        return EXIT_SUCCESS;

    }else if (arg == "16") {
        auto t1 = std::chrono::high_resolution_clock::now();

        for (int index = 0; index < 10000; index++){
            testPawn(g, false, legal_moves);
            testRooks(g, false, legal_moves);
            testBishops(g, false, legal_moves);
            testKnights(g, false, legal_moves);
            testQueen(g, false, legal_moves);
            testKing(g, false, legal_moves);
            testBasic(g, false, legal_moves);
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << duration.count() << " ms" << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}