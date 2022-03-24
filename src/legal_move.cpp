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
        if( white){
            for (uint8_t index : io_bitboard::get_positions(board._pieces[1]->pawns)) { //white
                if( (index >= 8) & (index <= 15)  ){ //firts move for a pawns
                    if( ( (board._pieces[1]->all.value >> (index+16)) & 0 ) & ((board._pieces[1]->all.value >> (index+8)) & 0) & ((board._pieces[0]->all.value >> (index+16)) & 0) & ((board._pieces[0]->all.value >> (index+8)) & 0) ){
                        struct movement mv = {index , static_cast<uint8_t>(index+16)};
                        res.push_back(mv);
                    }
                }
                if( (board._pieces[1]->all.value  >> (index+8)) & 0 ){ //advance from one
                    struct movement mv = {index , static_cast<uint8_t>(index+8)};
                    res.push_back(mv);
                }
                if( (board._pieces[0]->all.value  >> (index+7)) & 1 ){ //eat
                    struct movement mv = {index , static_cast<uint8_t>(index+7)};
                    res.push_back(mv);
                }
                if( (board._pieces[0]->all.value  >> (index+9)) & 1 ){ //eat
                    struct movement mv = {index , static_cast<uint8_t>(index+9)};
                    res.push_back(mv);
                }
            }
        }else{
            for (uint8_t index : io_bitboard::get_positions(board._pieces[0]->pawns)) {//black
                if( (index >= 48) & (index <= 55) ){                                     //firts move for a pawns
                    if( ((board._pieces[1]->all.value >> (index-16)) & 0) & ((board._pieces[1]->all.value >> (index-8)) & 0) & ((board._pieces[0]->all.value >> (index-16)) & 0) & ((board._pieces[0]->all.value >> (index-8)) & 0) ){
                        struct movement mv = {index , static_cast<uint8_t>(index-16)};
                        res.push_back(mv);
                    }
                }
                if( (board._pieces[0]->all.value >> (index-8)) & 0 ){//advance from one
                    struct movement mv = {index , static_cast<uint8_t>(index-16)};
                    res.push_back(mv);
                }
                if( (board._pieces[1]->all.value >> (index-7)) & 1){//eat
                    struct movement mv = {index , static_cast<uint8_t>(index-7)};
                    res.push_back(mv);
                }
                if( (board._pieces[1]->all.value >> (index-9)) & 1){//eat
                    struct movement mv = {index , static_cast<uint8_t>(index-9)};
                    res.push_back(mv);
                }
            }
        }
        return res;
    }

/*
    std::vector<uint64_t> legal_move_rooks(Bitboards *bitboards, bool white){
        std::vector<uint64_t> res;
        if( white){
            for (auto index : io_bitboard::get_positions(bitboards->White_rooks)){// white
                int index2;
                for (int i = index+8 ; i < 64 ; i=i+8){ //horizontal up
                    if( (board._pieces[1]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> i) & 1){
                        res.push_back(i);
                        break;
                    }else{
                        res.push_back(i);
                    }
                }
                for (int i = index-8 ; i > -1 ; i=i-8){ //horizontal down
                    if( (board._pieces[1]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> i) & 1){
                        res.push_back(i);
                        break;
                    }else{
                        res.push_back(i);
                    }
                }
                index2 = index;
                for (int i = index%8+1 ; i < 8; i++){//vertical move on right
                    index2++;
                    if( (board._pieces[1]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> index2) & 1){
                        res.push_back(index2);
                        break;
                    }else{
                        res.push_back(index2);
                    }
                }
                index2 = index;
                for (int i = index%8 -1 ; i > -1; i--){//vertical move on left
                    index2--;
                    if( (board._pieces[1]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> index2) & 1){
                        res.push_back(index2);
                        break;
                    }else{
                        res.push_back(index2);
                    }
                }
            }
        }else{
            for (auto index : io_bitboard::get_positions(bitboards->Black_rooks)){// black
                int index2;
                for (int i = index+8 ; i < 64 ; i=i+8){ //horizontal up
                    if( (board._pieces[0]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> i) & 1){
                        res.push_back(i);
                        break;
                    }else{
                        res.push_back(i);
                    }
                }
                for (int i = index-8 ; i > -1 ; i=i-8){ //horizontal down
                    if( (board._pieces[0]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> i) & 1){
                        res.push_back(i);
                        break;
                    }else{
                        res.push_back(i);
                    }
                }
                index2 = index;
                for (int i = index%8+1 ; i < 8; i++){//vertical move on right
                    index2++;
                    if( (board._pieces[0]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> index2) & 1){
                        res.push_back(index2);
                        break;
                    }else{
                        res.push_back(index2);
                    }
                }
                index2 = index;
                for (int i = index%8 -1 ; i > -1; i--){//vertical move on left
                    index2--;
                    if( (board._pieces[0]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> index2) & 1){
                        res.push_back(index2);
                        break;
                    }else{
                        res.push_back(index2);
                    }
                }
            }
        }
        return res;
    }*/

    /*std::vector<uint64_t> legal_move_knights(bool white){
        std::vector<uint64_t> res;
        if( white){

        }else{

        }
    }*/

    /*std::vector<uint64_t> legal_move_bishops(bool white);
    std::vector<uint64_t> legal_move_queen(bool white);
    std::vector<uint64_t> legal_move_king(bool white);*/

}