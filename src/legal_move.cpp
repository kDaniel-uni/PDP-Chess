//
// Pdp_echec university project
//

#include <string>
#include <vector>
#include <math.h>
#include "legal_move.h"
#include "game.h"
#include "bitboard_operations.h"
#include "move.h"

namespace pdp_chess{

    //std::vector<uint64_t> legal_move(Bitboards bitboard, bool white);



    std::vector<movement> legal_move_pawns(const board& board, bool white){
        std::vector<movement> res;
        uint8_t index2;
        if( white){
            for (uint8_t index : io_bitboard::get_positions(board._pieces[1]->pawns)) { //white
                if( ( index >= 8) & (index <= 15)  ){ //firts move for a pawns
                    if( !( (board._pieces[1]->all.value >> (index+16)) & 1 ) & !((board._pieces[1]->all.value >> (index+8)) & 1) & !((board._pieces[0]->all.value >> (index+16)) & 1) & !((board._pieces[0]->all.value >> (index+8)) & 1) ){
                        struct movement mv = {index , static_cast<uint8_t>(index+16)};
                        res.push_back(mv);
                    }
                }
                if( !((board._pieces[1]->all.value  >> (index+8)) & 1) ){ //advance from one
                    struct movement mv = {index , static_cast<uint8_t>(index+8)};
                    res.push_back(mv);
                }
                index2 = index%8;
                if( (board._pieces[0]->all.value  >> (index+7)) & 1 ){ //eat
                    index2--;
                    if( (index2 >=0) & (index2 < 8) ){
                        struct movement mv = {index , static_cast<uint8_t>(index+7)};
                        res.push_back(mv);
                    }
                }
                index2 = index%8;
                if( (board._pieces[0]->all.value  >> (index+9)) & 1 ){ //eat
                    index2++;
                    if ( (index2 >=0) & (index2 < 8) ){
                        struct movement mv = {index , static_cast<uint8_t>(index+9)};
                        res.push_back(mv);
                    }
                }
            }
        }else{
            for (uint8_t index : io_bitboard::get_positions(board._pieces[0]->pawns)) {//black
                if( (index >= 48) & (index <= 55) ){                                     //firts move for a pawns
                    if( !((board._pieces[1]->all.value >> (index-16)) & 1) & !((board._pieces[1]->all.value >> (index-8)) & 1) & !((board._pieces[0]->all.value >> (index-16)) & 1) & !((board._pieces[0]->all.value >> (index-8)) & 1) ){
                        struct movement mv = {index , static_cast<uint8_t>(index-16)};
                        res.push_back(mv);
                    }
                }
                if( !((board._pieces[0]->all.value >> (index-8)) & 1) ){//advance from one
                    struct movement mv = {index , static_cast<uint8_t>(index-8)};
                    res.push_back(mv);
                }
                index2 = index%8;
                if( (board._pieces[1]->all.value >> (index-7)) & 1){//eat
                    index2++;
                    if( (index2 >=0) & (index2 < 8) ){
                        struct movement mv = {index , static_cast<uint8_t>(index-7)};
                        res.push_back(mv);
                    }
                }
                index2 = index%8;
                if( (board._pieces[1]->all.value >> (index-9)) & 1){//eat
                    index2--;
                    if ( (index2 >=0) & (index2 < 8) ){
                        struct movement mv = {index , static_cast<uint8_t>(index-9)};
                        res.push_back(mv);
                    }
                }
            }
        }
        return res;
    }

    void move_line_vertical_horizontal(const board& board, uint8_t position_start, bool color_piece, std::vector<movement>& res){
        uint8_t index2;
        for (int i = position_start+8 ; i < 64 ; i=i+8){ //vertical up
            if( (board._pieces[color_piece]->all.value >> i) & 1 ){
                break;
            }else if( (board._pieces[!color_piece]->all.value >> i) & 1){
                struct movement mv = {position_start , static_cast<uint8_t>(i)};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , static_cast<uint8_t>(i)};
                res.push_back(mv);
            }
        }
        for (int i = position_start-8 ; i > -1 ; i=i-8){ //vertical down
            if( (board._pieces[color_piece]->all.value >> i) & 1){
                break;
            }else if( (board._pieces[!color_piece]->all.value >> i) & 1){
                struct movement mv = {position_start , static_cast<uint8_t>(i)};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , static_cast<uint8_t>(i)};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for (int i = position_start%8+1 ; i < 8; i++){//horizontal move on right
            index2++;
            if( (board._pieces[color_piece]->all.value >> index2) & 1){
                break;
            }else if( (board._pieces[!color_piece]->all.value >> index2) & 1){
                struct movement mv = {position_start , index2};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for (int i = position_start%8 -1 ; i > -1; i--){//horizontal move on left
            index2--;
            if( (board._pieces[color_piece]->all.value >> index2) & 1){
                break;
            }else if( (board._pieces[!color_piece]->all.value >> index2) & 1){
                struct movement mv = {position_start , index2};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , index2};
                res.push_back(mv);
            }
        }
    }

    std::vector<movement> legal_move_rooks(const board& board, bool white){
        std::vector<movement> res;
        for (uint8_t index : io_bitboard::get_positions(board._pieces[white]->rooks)){
            move_line_vertical_horizontal(board, index, white, res);
        }
        return res;
    }

    void move_diagonal(const board& board, uint8_t position_start, bool color_piece, std::vector<movement>& res){
        uint8_t index2;
        index2 = position_start;
        for ( int  i = position_start%8 +1 ; i<8 ; i++){ //diagonal up right
            index2 = index2 + 9;
            if( ((board._pieces[color_piece]->all.value >> index2) & 1) || (  index2 > 63)){ //piece of its color or move leave the board
                break;
            }else if ( (board._pieces[!color_piece]->all.value >> index2) & 1 ){
                struct movement mv = {position_start , index2};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start, index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for ( int i = position_start%8 -1 ; i >-1 ; i--){ //diagonal up left
            index2 = index2 + 7;
            if ( ((board._pieces[color_piece]->all.value >> index2) & 1) || (  index2 > 63) ){ //piece of its color or move leave the board
                break;
            }else if( (board._pieces[!color_piece]->all.value >> index2) & 1 ){
                struct movement mv = {position_start , index2};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for ( int  i = position_start%8 +1 ; i<8 ; i++){ //diagonal down right
            index2 = index2 - 7;
            if( ((board._pieces[color_piece]->all.value >> index2) & 1) || (  index2 < 0) || (  index2 > 63) ){ //piece of its color or move leave the board
                break;
            }else if ( (board._pieces[!color_piece]->all.value >> index2) & 1 ){
                struct movement mv = {position_start , index2};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , index2};
                res.push_back(mv);
            }
        }
        index2 = position_start;
        for ( int i = position_start%8 -1 ; i >-1 ; i--){ //diagonal down left
            index2 = index2 - 9;
            if ( ((board._pieces[color_piece]->all.value >> index2) & 1) || (  index2 < 0) || (  index2 > 63) ){ //piece of its color or move leave the board
                break;
            }else if( (board._pieces[!color_piece]->all.value >> index2) & 1 ){
                struct movement mv = {position_start , index2};
                res.push_back(mv);
                break;
            }else{
                struct movement mv = {position_start , index2};
                res.push_back(mv);
            }
        }
    }

    std::vector<movement> legal_move_bishops(const board& board, bool white){
        std::vector<movement> res;
        for (uint8_t index : io_bitboard::get_positions(board._pieces[white]->bishops)) {
            move_diagonal(board, index, white, res);
        }
        return res;
    }


    void move_this_position(const board& board,uint8_t position_start, uint8_t position_target, uint8_t position_x_target, bool color_piece, std::vector<movement>& res){
        if( (position_target < 0 | position_target > 63) | (position_x_target < 0 | position_x_target > 7) | (board._pieces[color_piece]->all.value >> position_target) & 1 ){
            return;
        }
        struct movement mv = {position_start , position_target};
        res.push_back(mv);
    }

    std::vector<movement> legal_move_knights(const board& board, bool white){
        std::vector<movement> res;
        for (uint8_t index : io_bitboard::get_positions(board._pieces[white]->bishops)){
            move_this_position( board, index, index-17, index%8 - 1, white, res);
            move_this_position( board, index, index-15, index%8 + 1, white, res);
            move_this_position( board, index, index-10, index%8 - 2, white, res);
            move_this_position( board, index, index-6, index%8 + 2, white, res);
            move_this_position( board, index, index+6, index%8 - 2, white, res);
            move_this_position( board, index, index+10, index%8 + 2, white, res);
            move_this_position( board, index, index+15, index%8 - 1, white, res);
            move_this_position( board, index, index+17, index%8 + 1, white, res);
        }
        return res;
    }

    std::vector<movement> legal_move_queen(const board& board, bool white){
        std::vector<movement> res;
        for (uint8_t index : io_bitboard::get_positions(board._pieces[white]->queen)) {
            move_diagonal(board, index, white, res);
            move_line_vertical_horizontal(board, index, white, res);
        }
        return res;
    }

    std::vector<movement> legal_move_king(const board& board, bool white){
        std::vector<movement> res;
        for (uint8_t index : io_bitboard::get_positions(board._pieces[white]->king)){
            move_this_position( board, index, index-9, index%8 - 1, white, res);
            move_this_position( board, index, index-8, index%8, white, res);
            move_this_position( board, index, index-7, index%8 + 1, white, res);
            move_this_position( board, index, index-1, index%8 - 1, white, res);
            move_this_position( board, index, index+1, index%8 + 1, white, res);
            move_this_position( board, index, index+7, index%8 - 1, white, res);
            move_this_position( board, index, index+8, index%8, white, res);
            move_this_position( board, index, index+9, index%8 + 1, white, res);
        }
        return res;
    }

}