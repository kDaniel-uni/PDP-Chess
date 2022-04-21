//
// Pdp_chess university project
//

#include <valuation/heuristic.h>

namespace pdp_chess {

    Heuristic::Heuristic(LegalMove& legalMove) { // Base values
        HeuristicParameters heuristicParameters = HeuristicParameters();

        pawns_value = heuristicParameters.pawns_value;
        rooks_value = heuristicParameters.rooks_value;
        bishops_value = heuristicParameters.bishops_value;
        knights_value = heuristicParameters.knights_value;
        queen_value = heuristicParameters.queen_value;
        king_value = heuristicParameters.king_value;
        backward_value = heuristicParameters.backward_value;
        isolated_value = heuristicParameters.isolated_value;
        doubled_value = heuristicParameters.doubled_value;
        legal_move_value = heuristicParameters.legal_move_value;
        forward_pawn_value = heuristicParameters.forward_pawn_value;
        this->legalMove = &legalMove;
    }

    Heuristic::Heuristic(LegalMove& legalMove, const HeuristicParameters &heuristicParameters) {
        pawns_value = heuristicParameters.pawns_value;
        rooks_value = heuristicParameters.rooks_value;
        bishops_value = heuristicParameters.bishops_value;
        knights_value = heuristicParameters.knights_value;
        queen_value = heuristicParameters.queen_value;
        king_value = heuristicParameters.king_value;
        backward_value = heuristicParameters.backward_value;
        isolated_value = heuristicParameters.isolated_value;
        doubled_value = heuristicParameters.doubled_value;
        legal_move_value = heuristicParameters.legal_move_value;
        forward_pawn_value = heuristicParameters.forward_pawn_value;
        this->legalMove = &legalMove;
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
                }
            }
        }
        return cmp;
    }

    int Heuristic::pawnForward(const Bitboard &current_pawns, const Bitboard &opponent_pawns) {

        if (forward_pawn_value == 0){
            return 0;
        }

        int score = 0;

        for (auto index : getPositionsV2(current_pawns.value)){
            uint8_t row = (index / 8);
            score += (1+row) * forward_pawn_value;
        }

        for (auto index : getPositionsV2(opponent_pawns.value)){
            uint8_t row = (index / 8);
            score -= (8 - row) * forward_pawn_value;
        }

        return score;
    }

    int Heuristic::nbLegalMove(const Board& board, bool white_turn){

        if (legal_move_value == 0){
            return 0;
        }

        std::vector<Move> white_legal_move = legalMove->GetLegalMoves(board, white_turn);
        std::vector<Move> black_legal_move = legalMove->GetLegalMoves(board, !white_turn);
        int legal_move_count = white_legal_move.size() - black_legal_move.size();

        return legal_move_count * legal_move_value;
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

        return value;
    }

    int Heuristic::evaluateBoard(const Board &board, bool color) {
        int value = evaluatePieces(*board._pieces[color], color) - evaluatePieces(*board._pieces[!color], !color);
        value += pawnForward(board._pieces[color]->pawns, board._pieces[!color]->pawns);
        value += nbLegalMove(board, color);
        return value;
    }
}
