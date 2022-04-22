//
// Pdp_chess university project
//

#include <string.h>
#include "bitboard_operations.h"
#include "move.h"
#include "engine/game.h"
#include "legal_move_v1.h"
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

bool testPawn(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("--------P--------p----------------------------------------------");
    game.board.draw();

    to_test = legalmove.getLegalMoves(game.board, true);

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

    to_test = legalmove.getLegalMoves(game.board, false);

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

bool testRooks(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("R---------------r-----------------------------------------------");
    game.board.draw();

    to_test = legalmove.getLegalMoves(game.board, true);
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

bool testBishops(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("---------B--------------------------b---------------------------");
    game.board.draw();

    to_test = legalmove.getLegalMoves(game.board, true);

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

bool testKnights(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("P----------n-----N----------------------------------------------");
    game.board.draw();


    to_test = legalmove.getLegalMoves(game.board, true);

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

bool testQueen(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("-----P-Q--------------------q----------p------------------------");
    game.board.draw();

    to_test = legalmove.getLegalMoves(game.board, true);

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

bool testKing(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("K-------p------p------------------------------------------------");
    game.board.draw();

    to_test = legalmove.getLegalMoves(game.board, true);

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

bool testBasic(Game &game, LegalMove &legalmove) {
    std::vector<Move> to_test;
    game.board.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");
    game.board.draw();

    to_test = legalmove.getLegalMoves(game.board, true);

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
    LegalMoveV1 legal_moves_v1 = LegalMoveV1();
    LegalMoveV2 legal_moves_v2 = LegalMoveV2();

    if (arg == "1") {
        return !testPawn(g, legal_moves_v1);

    } else if (arg == "2") {
        return !testPawn(g, legal_moves_v2);

    } else if (arg == "3") {
        return !testRooks(g, legal_moves_v1);

    } else if (arg == "4") {
        return !testRooks(g, legal_moves_v2);

    } else if (arg == "5") {
        return !testBishops(g, legal_moves_v1);

    } else if (arg == "6") {
        return !testBishops(g, legal_moves_v2);

    } else if (arg == "7") {
        return !testKnights(g, legal_moves_v1);

    } else if (arg == "8") {
        return !testKnights(g, legal_moves_v2);

    } else if (arg == "9") {
        return !testQueen(g, legal_moves_v1);

    } else if (arg == "10") {
        return !testQueen(g, legal_moves_v2);

    } else if (arg == "11") {
        return !testKing(g, legal_moves_v1);

    } else if (arg == "12") {
        return !testKing(g, legal_moves_v2);

    } else if (arg == "13") {
        return !testBasic(g, legal_moves_v1);

    } else if (arg == "14") {
        return !testBasic(g, legal_moves_v2);

    } else if (arg == "15") {
        auto t1 = std::chrono::high_resolution_clock::now();

        for (int index = 0; index < 10000; index++) {
            testPawn(g, legal_moves_v1);
            testRooks(g, legal_moves_v1);
            testBishops(g, legal_moves_v1);
            testKnights(g, legal_moves_v1);
            testQueen(g, legal_moves_v1);
            testKing(g, legal_moves_v1);
            testBasic(g, legal_moves_v1);
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << duration.count() << " ms" << std::endl;
        return EXIT_SUCCESS;

    } else if (arg == "16") {
        auto t1 = std::chrono::high_resolution_clock::now();

        for (int index = 0; index < 10000; index++) {
            testPawn(g, legal_moves_v2);
            testRooks(g, legal_moves_v2);
            testBishops(g, legal_moves_v2);
            testKnights(g, legal_moves_v2);
            testQueen(g, legal_moves_v2);
            testKing(g, legal_moves_v2);
            testBasic(g, legal_moves_v2);
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << duration.count() << " ms" << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}