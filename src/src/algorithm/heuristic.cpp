//
// Pdp_chess university project
//


#include <heuristic.h>

namespace pdp_chess {
    Heuristic::Heuristic(){
        pawns_value = 1;
        rooks_value = 5;
        bishops_value = 3;
        knights_value = 3;
        queen_value = 9;
        king_value = 200; 
    }

    Heuristic::Heuristic(int p_v, int r_v, int b_v, int kn_v, int q_v, int k_v) {
        pawns_value = p_v;
        rooks_value = r_v;
        bishops_value = b_v;
        knights_value = kn_v;
        queen_value = q_v;
        king_value = k_v;
    }

    int Heuristic::nbBackward(const Bitboard &bitboard){
        return 0;
    }

    int Heuristic::nbDoubled(const Bitboard &bitboard){
        return 0;
    }

    int Heuristic::nbIsolated(const Bitboard &bitboard){
        return 0;
    }

    int Heuristic::evaluatePieces(const Bitboards * bitboards){
        int value = 0;
        for (int i = 0; i < 6; i++) {
            Bitboard* b = bitboards->list[i];
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
        return value;
    }

    int Heuristic::evaluateBoard(const Board &board, bool white_turn) {
        int value = evaluatePieces(board._pieces[white]) - evaluatePieces(board._pieces[black]);
        if (white_turn)
            return value;
        else
            return -1 * value;
    }
}
