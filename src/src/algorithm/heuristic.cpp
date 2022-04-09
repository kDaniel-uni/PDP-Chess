//
// Pdp_chess university project
//


#include <heuristic.h>
#include <legal_move.h>

namespace pdp_chess {
    Heuristic::Heuristic(){
        pawns_value = 1;
        rooks_value = 5;
        bishops_value = 3;
        knights_value = 3;
        queen_value = 9;
        king_value = 200; 
        backward_value = 0.5;
        isolated_value = 0.5;
        doubled_value = 0.5;
    }

    Heuristic::Heuristic(float p_v, float r_v, float b_v, float kn_v, float q_v, float k_v, float back_v, float i_v, float d_v) {
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

    float Heuristic::whiteNbBackward(const Bitboard& bitboard){
        float cmp = 0;
        for(int i = 0; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                bool back = false;
                if(i%8 != 0){
                    for(int j = i+7; j < BOARD_SIZE; j+=8){ //On regarde les cases de la colonne de gauche au dessus de notre pion
                        if((bitboard.value >> j) & 1){
                            back = true;
                            break;
                        }
                    }
                    for(int j = (i-1)%8; j <= i-1; j+=8){ //On regarde les cases de la colonne de gauche en dessous de notre pion
                        if((bitboard.value >> j) & 1){
                            back = false;
                            break;
                        }
                    }
                }
                if(i%8 != 7){
                    for(int j = i+1; j < BOARD_SIZE; j+=8){ //On regarde les cases de la colonne de droite au dessus de notre pion
                        if((bitboard.value >> j) & 1){
                            back = true;
                            break;
                        }
                    }
                    for(int j = (i+1)%8; j <= i+1; j+=8){ //On regarde les cases de la colonne de droite en dessous de notre pion
                        if((bitboard.value >> j) & 1){
                            back = false;
                            break;
                        }
                    }
                }
                for(int j = i+8; j < BOARD_SIZE; j+=8){ //On regarde les cases au dessus de notre pion
                        if((bitboard.value >> j) & 1){
                            back = true;
                            break;
                        }
                    }
                for(int j = i%8; j < i; j+=8){ //On regarde les cases au dessous de notre pion
                    if((bitboard.value >> j) & 1){ 
                        back = false;
                        break;
                    }
                }
                if(back){
                    cmp++;
                }
            }
        }
        return cmp;
    }
    float Heuristic::blackNbBackward(const Bitboard& bitboard){
        float cmp = 0;
        for(int i = 0; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                bool back = false;
                if(i%8 != 0){
                    for(int j = (i-1)%8; j < i-1; j+=8){ //On regarde les cases de la colonne de gauche en dessous de notre pion
                        if((bitboard.value >> j) & 1){
                            back = true;
                            break;
                        }
                    }
                    for(int j = i-1; j < BOARD_SIZE; j+=8){ //On regarde les cases de la colonne de gauche au dessus de notre pion
                        if((bitboard.value >> j) & 1){
                            back = false;
                            break;
                        }
                    }
                }
                if(i%8 != 7){
                    for(int j = (i+1)%8; j < i-1; j+=8){ //On regarde les cases de la colonne de droite en dessous de notre pion
                        if((bitboard.value >> j) & 1){
                            back = true;
                            break;
                        }
                    }
                    for(int j = i+1; j < BOARD_SIZE; j+=8){ //On regarde les cases de la colonne de droite au dessus de notre pion
                        if((bitboard.value >> j) & 1){
                            back = false;
                            break;
                        }
                    }
                }/*
                for(int j = i%8; j < i-8; j+=8){ //On regarde les cases en dessous de notre pion
                    if((bitboard.value >> j) & 1){
                        back = true;
                        break;
                    }
                }
                for(int j = i%8; j < i; j+=8){
                    if((bitboard.value >> j) & 1){ //On regarde les cases au dessus de notre pion
                        back = false;
                        break;
                    }
                }*/
                if(back){
                    cmp++;
                }
            }
        }
        return cmp;
    }


    float Heuristic::nbDoubled(const Bitboard& bitboard){
        float cmp = 0;
        for(int i = 8; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                if((bitboard.value >> i - 8) & 1){
                    cmp++;
                }
            }
        }
        return cmp;
    }

    float Heuristic::nbIsolated(const Bitboard& bitboard){
        float cmp = 0;
        for(int i = 0; i < BOARD_SIZE; i++){
            if((bitboard.value >> i) & 1) {
                bool isolated = true;
                if(i%8 != 0){
                    for(int j = i-1; j < BOARD_SIZE; j+=8){
                        if((bitboard.value >> j) & 1){
                            isolated = false;
                            break;
                        }
                    }
                }
                if(i%8 != 7){
                    for(int j = i+1; j < BOARD_SIZE; j+=8){
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
                }
            }
        }
        return cmp;
    }

    float Heuristic::nbLegalMove(const Board& board, bool white_turn){
        float legal_move_count = 0;

        std::vector<Move> white_legal_move = legal_move(board, white_turn);
        std::vector<Move> black_legal_move = legal_move(board, !white_turn);
        legal_move_count = white_legal_move.size() - black_legal_move.size();
        if(white_turn)
            return legal_move_count;
        else
            return -1*legal_move_count;
    }

    float Heuristic::evaluatePieces(const PlayerState& player_state, bool is_white){
        float value = 0;
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
        printf("val = %f, ",value);
        value -= doubled_value * nbDoubled(*player_state.list[0]);
        printf("doubled = %f, ",value);
        value -= isolated_value * nbIsolated(*player_state.list[0]);
        printf("isolated = %f, ",value);
        if (is_white) { 
            value -= backward_value * whiteNbBackward(*player_state.list[0]); 
        } else {
            value -= backward_value * blackNbBackward(*player_state.list[0]);
        }
        printf("backward = %f\n",value);
        return value;
    }

    float Heuristic::evaluateBoard(const Board &board, bool white_turn) {
        float value = evaluatePieces(*board._pieces[white], true) - evaluatePieces(*board._pieces[black], false);
        //value += nbLegalMove(board, white_turn);
        if (white_turn)
            return value;
        else
            return -1 * value;
    }
}
