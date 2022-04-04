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
        backward_value = 0.5;
    }

    Heuristic::Heuristic(float p_v, float r_v, float b_v, float kn_v, float q_v, float k_v, float back_v) {
        pawns_value = p_v;
        rooks_value = r_v;
        bishops_value = b_v;
        knights_value = kn_v;
        queen_value = q_v;
        king_value = k_v;
        backward_value = back_v;
    }

    float Heuristic::nbBackward(const Bitboard * bitboard){
        int cmp = 0;
        for(int i = 8; i < BOARD_SIZE; i++){
            if((bitboard->value >> i) & 1) {
                if((bitboard->value >> i - 8) & 1){
                    cmp++;
                }
            }
        }
        return cmp;
    }

    float Heuristic::nbDoubled(const Bitboard * bitboard){
        for(int i = 0; i < BOARD_SIZE; i++){
            if((bitboard->value >> i) & 1) {
            }
        }
        return 0;
    }

    float Heuristic::nbIsolated(const Bitboard * bitboard){
        for(int i = 0; i < BOARD_SIZE; i++){
            if((bitboard->value >> i) & 1) {

            }
        }
        return 0;
    }

    float Heuristic::evaluatePieces(const Bitboards * bitboards){
        float value = 0;
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
        value += backward_value*nbBackward(bitboards->list[0]); 
        return value;
    }

    float Heuristic::evaluateBoard(const Board &board, bool white_turn) {
        float value = evaluatePieces(board._pieces[white]) - evaluatePieces(board._pieces[black]);
        if (white_turn)
            return value;
        else
            return -1 * value;
    }
}
