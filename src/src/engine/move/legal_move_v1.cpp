//
// Pdp_chess university project
//

#include "legal_move_v1.h"

namespace pdp_chess{

    std::vector<Move> LegalMoveV1::getLegalMoves(const Board& board, bool white){
        std::vector<Move> res;
        std::vector<Move> res2 = legal_move_pawns(board, white);
        res.insert(res.end(), res2.begin(), res2.end());
        res2 = legal_move_rooks(board, white);
        res.insert(res.end(), res2.begin(), res2.end());
        res2 = legal_move_bishops(board, white);
        res.insert(res.end(), res2.begin(), res2.end());
        res2 = legal_move_knights(board, white);
        res.insert(res.end(), res2.begin(), res2.end());
        res2 = legal_move_queen(board, white);
        res.insert(res.end(), res2.begin(), res2.end());
        res2 = legal_move_king(board, white);
        res.insert(res.end(), res2.begin(), res2.end());
        return res;
    }

    std::vector<Move> LegalMoveV1::legal_move_pawns(const Board& board, bool is_white){
        std::vector<Move> res;
        uint8_t index2;
        char type = (char) ('p' - (is_white * 32));
        
        if( is_white ){
            for (uint8_t index : getPositionsV1(board.pieces[white]->pawns.value)) { //white
                if( ( index >= 8) & (index <= 15)  ){ //pawn base position
                    if( !( (board.pieces[white]->all.value >> (index+16)) & 1 ) & !((board.pieces[white]->all.value >> (index+8)) & 1) & !((board.pieces[black]->all.value >> (index+16)) & 1) & !((board.pieces[black]->all.value >> (index+8)) & 1) ){
                        Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index+16)};
                        res.push_back(mv);
                    }
                }
                if( !((board.pieces[white]->all.value  >> (index+8)) & 1) & !((board.pieces[black]->all.value >> (index-8)) & 1) ){ //advance from one
                    Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index+8)};
                    res.push_back(mv);
                }
                index2 = index%8;
                if( (board.pieces[black]->all.value  >> (index+7)) & 1 ){ //eat
                    index2--;
                    if( (index2 >=0) & (index2 < 8) ){
                        Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index+7)};
                        res.push_back(mv);
                    }
                }
                index2 = index%8;
                if( (board.pieces[black]->all.value  >> (index+9)) & 1 ){ //eat
                    index2++;
                    if ( (index2 >=0) & (index2 < 8) ){
                        Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index+9)};
                        res.push_back(mv);
                    }
                }
            }
            return res;
        }

        for (uint8_t index : getPositionsV1(board.pieces[0]->pawns.value)) {//black
            if( (index >= 48) & (index <= 55) ){                                     //firts move for a pawns
                if( !((board.pieces[white]->all.value >> (index-16)) & 1) & !((board.pieces[white]->all.value >> (index-8)) & 1) & !((board.pieces[black]->all.value >> (index-16)) & 1) & !((board.pieces[black]->all.value >> (index-8)) & 1) ){
                    Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index-16)};
                    res.push_back(mv);
                }
            }
            if( !((board.pieces[white]->all.value >> (index-8)) & 1) & !((board.pieces[black]->all.value >> (index-8)) & 1) ){//advance from one
                Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index-8)};
                res.push_back(mv);
            }
            index2 = index%8;
            if( (board.pieces[white]->all.value >> (index-7)) & 1){//eat
                index2++;
                if( (index2 >=0) & (index2 < 8) ){
                    Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index-7)};
                    res.push_back(mv);
                }
            }
            index2 = index%8;
            if( (board.pieces[white]->all.value >> (index-9)) & 1){//eat
                index2--;
                if ( (index2 >=0) & (index2 < 8) ){
                    Move mv = {.start_position = index, .start_type = type, .target_position = (uint8_t)(index-9)};
                    res.push_back(mv);
                }
            }
        }
        return res;
    }

    void LegalMoveV1::moveLineVerticalHorizontal(const Board &board, uint8_t position_start, bool color_piece, std::vector<Move>& res){
        uint8_t index2;
        for (int i = position_start+8 ; i < 64 ; i=i+8){ //vertical up
            if( (board.pieces[color_piece]->all.value >> i) & 1 ){
                break;
            }else if( (board.pieces[!color_piece]->all.value >> i) & 1){
                Move mv = {.start_position = position_start , .target_position = (uint8_t)(i)};
                res.push_back(mv);
                break;
            }else{
                Move mv = {.start_position = position_start , .target_position = (uint8_t)(i)};
                res.push_back(mv);
            }
        }
        for (int i = position_start-8 ; i > -1 ; i=i-8){ //vertical down
            if( (board.pieces[color_piece]->all.value >> i) & 1){
                break;
            }else if( (board.pieces[!color_piece]->all.value >> i) & 1){
                Move mv = {.start_position = position_start , .target_position = (uint8_t)(i)};
                res.push_back(mv);
                break;
            }else{
                Move mv = {.start_position = position_start , .target_position = (uint8_t)(i)};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for (int i = position_start%8+1 ; i < 8; i++){//horizontal move on right
            index2++;
            if( (board.pieces[color_piece]->all.value >> index2) & 1){
                break;
            }else if( (board.pieces[!color_piece]->all.value >> index2) & 1){
                Move mv = {.start_position = position_start , .target_position = index2};
                res.push_back(mv);
                break;
            }else{
                Move mv = {.start_position = position_start , .target_position = index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for (int i = position_start%8 -1 ; i > -1; i--){//horizontal move on left
            index2--;
            if( (board.pieces[color_piece]->all.value >> index2) & 1){
                break;
            }else if( (board.pieces[!color_piece]->all.value >> index2) & 1){
                Move mv = {.start_position = position_start , .target_position = index2};
                res.push_back(mv);
                break;
            }else{
                Move mv = {.start_position = position_start , .target_position = index2};
                res.push_back(mv);
            }
        }
    }

    std::vector<Move> LegalMoveV1::legal_move_rooks(const Board& board, bool white){
        std::vector<Move> res;
        for (uint8_t index : getPositionsV1(board.pieces[white]->rooks.value)){
            moveLineVerticalHorizontal(board, index, white, res);
        }

        char type = (char) ('r' - (white * 32));

        for (auto& element : res){
            element.start_type = type;
        }

        return res;
    }

    void LegalMoveV1::moveDiagonal(const Board &board, uint8_t position_start, bool color_piece, std::vector<Move>& res){
        uint8_t index2;
        index2 = position_start;
        for ( int  i = position_start%8 +1 ; i<8 ; i++){ //diagonal up right
            index2 = index2 + 9;
            if( ((board.pieces[color_piece]->all.value >> index2) & 1) || (  index2 > 63)){ //piece of its color or move leave the board
                break;
            }else if ( (board.pieces[!color_piece]->all.value >> index2) & 1 ){
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
                break;
            }else{
                Move mv = { .start_position = position_start, .target_position = index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for ( int i = position_start%8 -1 ; i >-1 ; i--){ //diagonal up left
            index2 = index2 + 7;
            if ( ((board.pieces[color_piece]->all.value >> index2) & 1) || (  index2 > 63) ){ //piece of its color or move leave the board
                break;
            }else if( (board.pieces[!color_piece]->all.value >> index2) & 1 ){
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
                break;
            }else{
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for ( int  i = position_start%8 +1 ; i<8 ; i++){ //diagonal down right
            index2 = index2 - 7;
            if( ((board.pieces[color_piece]->all.value >> index2) & 1) || (  index2 < 0) || (  index2 > 63) ){ //piece of its color or move leave the board
                break;
            }else if ( (board.pieces[!color_piece]->all.value >> index2) & 1 ){
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
                break;
            }else{
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for ( int i = position_start%8 -1 ; i >-1 ; i--){ //diagonal down left
            index2 = index2 - 9;
            if ( ((board.pieces[color_piece]->all.value >> index2) & 1) || (  index2 < 0) || (  index2 > 63) ){ //piece of its color or move leave the board
                break;
            }else if( (board.pieces[!color_piece]->all.value >> index2) & 1 ){
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
                break;
            }else{
                Move mv = { .start_position = position_start , .target_position = index2};
                res.push_back(mv);
            }
        }
    }

    std::vector<Move> LegalMoveV1::legal_move_bishops(const Board& board, bool white){
        std::vector<Move> res;
        for (uint8_t index : getPositionsV1(board.pieces[white]->bishops.value)) {
            moveDiagonal(board, index, white, res);
        }

        char type = (char) ('b' - (white * 32));

        for (auto& element : res){
            element.start_type = type;
        }

        return res;
    }


    void LegalMoveV1::moveThisPosition(const Board &board, uint8_t position_start, uint8_t position_target, uint8_t position_x_target, bool color_piece, std::vector<Move>& res){
        if( (position_target < 0 | position_target > 63) | (position_x_target < 0 | position_x_target > 7) | (board.pieces[color_piece]->all.value >> position_target) & 1 ){
            return;
        }
        Move mv = {.start_position = position_start , .target_position = position_target};
        res.push_back(mv);
    }

    std::vector<Move> LegalMoveV1::legal_move_knights(const Board& board, bool white){
        std::vector<Move> res;
        for (uint8_t index : getPositionsV1(board.pieces[white]->knights.value)){
            moveThisPosition( board, index, index-17, index%8 - 1, white, res);
            moveThisPosition( board, index, index-15, index%8 + 1, white, res);
            moveThisPosition( board, index, index-10, index%8 - 2, white, res);
            moveThisPosition( board, index, index-6, index%8 + 2, white, res);
            moveThisPosition( board, index, index+6, index%8 - 2, white, res);
            moveThisPosition( board, index, index+10, index%8 + 2, white, res);
            moveThisPosition( board, index, index+15, index%8 - 1, white, res);
            moveThisPosition( board, index, index+17, index%8 + 1, white, res);
        }

        char type = (char) ('n' - (white * 32));

        for (auto& element : res){
            element.start_type = type;
        }

        return res;
    }

    std::vector<Move> LegalMoveV1::legal_move_queen(const Board& board, bool white){
        std::vector<Move> res;
        for (uint8_t index : getPositionsV1(board.pieces[white]->queen.value)) {
            moveDiagonal(board, index, white, res);
            moveLineVerticalHorizontal(board, index, white, res);
        }

        char type = (char) ('q' - (white * 32));

        for (auto& element : res){
            element.start_type = type;
        }

        return res;
    }

    std::vector<Move> LegalMoveV1::legal_move_king(const Board& board, bool white){
        std::vector<Move> res;
        for (uint8_t index : getPositionsV1(board.pieces[white]->king.value)){
            moveThisPosition( board, index, index-9, index%8 - 1, white, res);
            moveThisPosition( board, index, index-8, index%8, white, res);
            moveThisPosition( board, index, index-7, index%8 + 1, white, res);
            moveThisPosition( board, index, index-1, index%8 - 1, white, res);
            moveThisPosition( board, index, index+1, index%8 + 1, white, res);
            moveThisPosition( board, index, index+7, index%8 - 1, white, res);
            moveThisPosition( board, index, index+8, index%8, white, res);
            moveThisPosition( board, index, index+9, index%8 + 1, white, res);
        }

        char type = (char) ('k' - (white * 32));

        for (auto& element : res){
            element.start_type = type;
        }

        return res;
    }

}