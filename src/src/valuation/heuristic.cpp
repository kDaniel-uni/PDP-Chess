//
// Pdp_chess university project
//

#include <valuation/heuristic.h>

namespace pdp_chess {

    Heuristic::Heuristic(LegalMove &legal_move) { // Base values
        HeuristicParameters heuristic_parameters = HeuristicParameters();

        pawns_value = heuristic_parameters.pawns_value;
        rooks_value = heuristic_parameters.rooks_value;
        bishops_value = heuristic_parameters.bishops_value;
        knights_value = heuristic_parameters.knights_value;
        queen_value = heuristic_parameters.queen_value;
        king_value = heuristic_parameters.king_value;
        backward_value = heuristic_parameters.backward_value;
        isolated_value = heuristic_parameters.isolated_value;
        doubled_value = heuristic_parameters.doubled_value;
        legal_move_value = heuristic_parameters.legal_move_value;
        forward_pawn_value = heuristic_parameters.forward_pawn_value;
        this->legal_move = &legal_move;
    }

    Heuristic::Heuristic(LegalMove &legal_move, const HeuristicParameters &heuristic_parameters) {
        pawns_value = heuristic_parameters.pawns_value;
        rooks_value = heuristic_parameters.rooks_value;
        bishops_value = heuristic_parameters.bishops_value;
        knights_value = heuristic_parameters.knights_value;
        queen_value = heuristic_parameters.queen_value;
        king_value = heuristic_parameters.king_value;
        backward_value = heuristic_parameters.backward_value;
        isolated_value = heuristic_parameters.isolated_value;
        doubled_value = heuristic_parameters.doubled_value;
        legal_move_value = heuristic_parameters.legal_move_value;
        forward_pawn_value = heuristic_parameters.forward_pawn_value;
        this->legal_move = &legal_move;
    }

    int Heuristic::whiteNbBackward(const Bitboard &bitboard) {

        if (backward_value == 0) {
            return 0;
        }

        int cmp = 0;
        for (int i = 8; i < BOARD_SIZE; i++) {
            if ((bitboard.value >> i) & 1) {
                bool back = false;
                if (i % 8 != 0) {
                    if ((bitboard.value >> i + 7) & 1) {
                        back = true;
                    }
                    if ((bitboard.value >> i - 9) & 1) {
                        back = false;
                    }
                }
                if (i % 8 != 7) {
                    if ((bitboard.value >> i + 9) & 1) {
                        back = true;
                    }
                    if ((bitboard.value >> i - 7) & 1) {
                        back = false;
                    }
                }
                if (back) {
                    cmp++;
                }
            }
        }
        return cmp;
    }

    int Heuristic::blackNbBackward(const Bitboard &bitboard) {

        if (backward_value == 0) {
            return 0;
        }

        int cmp = 0;
        for (int i = 0; i < BOARD_SIZE - 8; i++) {
            if ((bitboard.value >> i) & 1) {
                bool back = false;
                if (i % 8 != 0) {
                    if ((bitboard.value >> i - 9) & 1) {
                        back = true;
                    }
                    if ((bitboard.value >> i + 7) & 1) {
                        back = false;
                    }
                }
                if (i % 8 != 7) {
                    if ((bitboard.value >> i - 7) & 1) {
                        back = true;
                    }
                    if ((bitboard.value >> i + 9) & 1) {
                        back = false;
                    }
                }
                if (back) {
                    cmp++;
                }
            }
        }
        return cmp;
    }


    int Heuristic::nbDoubled(const Bitboard &bitboard) {

        if (doubled_value == 0) {
            return 0;
        }

        int cmp = 0;
        for (int i = 8; i < BOARD_SIZE; i++) {
            if ((bitboard.value >> i) & 1) {
                if ((bitboard.value >> i - 8) & 1) {
                    cmp++;
                }
            }
        }
        return cmp;
    }

    int Heuristic::nbIsolated(const Bitboard &bitboard) {

        if (isolated_value == 0) {
            return 0;
        }

        int cmp = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((bitboard.value >> i) & 1) {
                bool isolated = true;
                if (i % 8 != 0) {
                    for (int j = (i % 8) - 1; j < BOARD_SIZE; j += 8) {
                        if ((bitboard.value >> j) & 1) {
                            isolated = false;
                            break;
                        }
                    }
                }
                if (i % 8 != 7) {
                    for (int j = (i % 8) + 1; j < BOARD_SIZE; j += 8) {
                        if ((bitboard.value >> j) & 1) {
                            isolated = false;
                            break;
                        }
                    }
                }
                for (int j = i % 8; j < BOARD_SIZE; j += 8) {
                    if ((bitboard.value >> j) & 1 && j != i) {
                        isolated = false;
                        break;
                    }
                }
                if (isolated) {
                    cmp++;
                }
            }
        }
        return cmp;
    }

    int Heuristic::whitePawnForward(const Bitboard &current_pawns) {

        if (forward_pawn_value == 0) {
            return 0;
        }

        int score = 0;

        for (auto index : getPositionsV1(current_pawns.value)) {
            uint8_t row = (index / 8);
            score += (1 + row) * forward_pawn_value;
        }

        return score;
    }

    int Heuristic::blackPawnForward(const Bitboard &current_pawns) {

        if (forward_pawn_value == 0) {
            return 0;
        }

        int score = 0;

        for (auto index : getPositionsV1(current_pawns.value)) {
            uint8_t row = (index / 8);
            score -= (8 - row) * forward_pawn_value;
        }

        return score;
    }

    int Heuristic::nbLegalMove(const Board &board, bool color) {

        if (legal_move_value == 0) {
            return 0;
        }

        std::vector<Move> legal_moves = legal_move->getLegalMoves(board, color);
        int legal_move_count = legal_moves.size();

        return legal_move_count * legal_move_value;
    }

    int Heuristic::evaluatePieces(const PlayerState &player_state, bool is_white) {

        int value = 0;
        for (int i = 0; i < 6; i++) {
            Bitboard *b = player_state.list[i];
            for (int j = 0; j < BOARD_SIZE; j++) {
                if ((b->value >> j) & 1) {
                    if (i == 0)
                        value += pawns_value;
                    if (i == 1)
                        value += rooks_value;
                    if (i == 2)
                        value += bishops_value;
                    if (i == 3)
                        value += knights_value;
                    if (i == 4)
                        value += queen_value;
                    if (i == 5)
                        value += king_value;
                }
            }
        }
        value -= doubled_value * nbDoubled(*player_state.list[0]);
        value -= isolated_value * nbIsolated(*player_state.list[0]);

        if (is_white) {
            value -= backward_value * whiteNbBackward(*player_state.list[0]);
            value += whitePawnForward(player_state.pawns);
        } else {
            value -= backward_value * blackNbBackward(*player_state.list[0]);
            value += blackPawnForward(player_state.pawns);
        }

        return value;
    }

    int Heuristic::evaluateBoard(const Board &board, bool color) {
        int value = evaluatePieces(*board.pieces[white], white) - evaluatePieces(*board.pieces[black], black);

        value += nbLegalMove(board, white) - nbLegalMove(board, black);

        if (color) {
            return value;
        } else {
            return -value;
        }

    }
}
