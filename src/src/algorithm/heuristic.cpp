//
// Pdp_chess university project
//


#include <heuristic.h>
#include <legal_move.h>

namespace pdp_chess {
    Heuristic::Heuristic(){
        pawns_value = 10;
        rooks_value = 50;
        bishops_value = 30;
        knights_value = 30;
        queen_value = 90;
        king_value = 2000; 
        backward_value = 5;
        isolated_value = 5;
        doubled_value = 5;
    }

    Heuristic::Heuristic(int p_v, int r_v, int b_v, int kn_v, int q_v, int k_v, int back_v, int i_v, int d_v) {
        pawns_value = p_v;
        rooks_value = r_v;
        bishops_value = b_v;
        knights_value = kn_v;
        queen_value = q_v;
        king_value = k_v;
        backward_value = back_v;
        isolated_value = i_v;
        doubled_value = d_v;
    }

    int Heuristic::whiteNbBackward(const Bitboard& bitboard){
        int cmp = 0;
        for(int i = 8; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                bool back = false;
                if(i%8 != 0){
                    if((bitboard.value >> i+7) & 1){
                            back = true;
                    }
                    if((bitboard.value >> i-9) & 1){
                            back = false;
                    }
                }
                if(i%8 != 7){
                    if((bitboard.value >> i+9) & 1){
                        back = true;
                    }
                    if((bitboard.value >> i-7) & 1){
                        back = false;
                    }
                }
                if(back){
                    cmp++;
                }
            }
        }
        return cmp;
    }
    int Heuristic::blackNbBackward(const Bitboard& bitboard){
        int cmp = 0;
        for(int i = 0; i < BOARD_SIZE-8; i++){
            if((bitboard.value >> i) & 1) {
                bool back = false;
                if(i%8 != 0){
                    if((bitboard.value >> i-9) & 1){
                       back = true;
                    }
                    if((bitboard.value >> i+7) & 1){
                        back = false;
                    }
                }
                if(i%8 != 7){
                    if((bitboard.value >> i-7) & 1){
                        back = true;
                    }
                    if((bitboard.value >> i+9) & 1){
                        back = false;
                    }
                }
                if(back){
                    cmp++;
                }
            }
        }
        return cmp;
    }


    int Heuristic::nbDoubled(const Bitboard& bitboard){
        int cmp = 0;
        for(int i = 8; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                if((bitboard.value >> i - 8) & 1){
                    cmp++;
                }
            }
        }
        return cmp;
    }

    int Heuristic::nbIsolated(const Bitboard& bitboard){
        int cmp = 0;
        for(int i = 0; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                bool isolated = true;
                if(i%8 != 0){
                    for(int j = (i%8)-1; j < BOARD_SIZE; j+=8){
                        if((bitboard.value >> j) & 1){
                            isolated = false;
                            break;
                        }
                    }
                }
                if(i%8 != 7){
                    for(int j = (i%8)+1; j < BOARD_SIZE; j+=8){
                        if((bitboard.value >> j) & 1){
                            isolated = false;
                            break;
                        }
                    }
                }
                for(int j = i%8; j < BOARD_SIZE; j+=8){
                    if((bitboard.value >> j) & 1 && j != i){
                        isolated = false;
                        break;
                    }
                }
                if(isolated){
                    cmp++;
                    printf("%d\n", i);
                }
            }
        }
        return cmp;
    }

    int Heuristic::nbLegalMove(const Board& board, bool white_turn){
        int legal_move_count = 0;

        std::vector<Move> white_legal_move = legal_move(board, white_turn);
        std::vector<Move> black_legal_move = legal_move(board, !white_turn);
        legal_move_count = white_legal_move.size() - black_legal_move.size();
        if(white_turn)
            return legal_move_count;
        else
            return -1*legal_move_count;
    }

    int Heuristic::evaluatePieces(const PlayerState& player_state, bool is_white){
        int value = 0;
        for (int i = 0; i < 6; i++) {
            Bitboard* b = player_state.list[i];
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
        //printf("Initial value = %f, ",value);
        value -= doubled_value * nbDoubled(*player_state.list[0]);
        //printf("after doubled pieces = %f, ",value);
        value -= isolated_value * nbIsolated(*player_state.list[0]);
        //printf("after isolated pieces = %f, ",value);
        if (is_white) { 
            value -= backward_value * whiteNbBackward(*player_state.list[0]); 
        } else {
            value -= backward_value * blackNbBackward(*player_state.list[0]);
        }
        //printf("after backward pieces = %f\n",value);
        return value;
    }

    int Heuristic::evaluateBoard(const Board &board, bool white_turn) {
        int value = evaluatePieces(*board._pieces[white], true) - evaluatePieces(*board._pieces[black], false);
        //value += nbLegalMove(board, white_turn);
        if (white_turn)
            return value;
        else
            return -1 * value;
    }
}
