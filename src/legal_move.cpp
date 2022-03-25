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

    int* converte_to_2D(uint8_t u){
        static int tab[2];
        tab[0] = (int) u%8;
        tab[1] = (int) u/8;
        return tab;
    }
    //std::vector<uint64_t> legal_move(Bitboards bitboard, bool white);



    std::vector<movement> legal_move_pawns(const board& board, bool white){
        std::vector<movement> res;
        int *tab;
        if( white){
            for (uint8_t index : io_bitboard::get_positions(board._pieces[1]->pawns)) { //white
                tab = pdp_chess::converte_to_2D( index );
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
                if( (board._pieces[0]->all.value  >> (index+7)) & 1 ){ //eat
                    tab[0]--;
                    if( (tab[0] >=0) & (tab[0] < 8) ){
                        struct movement mv = {index , static_cast<uint8_t>(index+7)};
                        res.push_back(mv);
                    }
                }
                if( (board._pieces[0]->all.value  >> (index+9)) & 1 ){ //eat
                    tab[0]++;
                    if ( (tab[0] >=0) & (tab[0] < 8) ){
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


    std::vector<movement> legal_move_rooks(const board& board, bool white){
        std::vector<movement> res;
        int *tab;
        if( white){
            for (uint8_t index : io_bitboard::get_positions(board._pieces[1]->rooks)){// white
                int index2;
                for (int i = index+8 ; i < 64 ; i=i+8){ //vertical up
                    if( (board._pieces[1]->all.value >> i) & 1 ){
                        break;
                    }else if( (board._pieces[0]->all.value >> i) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                    }
                }
                for (int i = index-8 ; i > -1 ; i=i-8){ //vertical down
                    if( (board._pieces[1]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> i) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                    }
                }
                index2 = index;
                for (int i = index%8+1 ; i < 8; i++){//horizontal move on right
                    index2++;
                    if( (board._pieces[1]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> index2) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                    }
                }
                index2 = index;
                for (int i = index%8 -1 ; i > -1; i--){//horizontal move on left
                    index2--;
                    if( (board._pieces[1]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[0]->all.value >> index2) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                    }
                }
            }
        }else{
            for (auto index : io_bitboard::get_positions(board._pieces[0]->rooks)){// black
                int index2;
                for (int i = index+8 ; i < 64 ; i=i+8){ //vertical up
                    if( (board._pieces[0]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> i) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                    }
                }
                for (int i = index-8 ; i > -1 ; i=i-8){ //vertical down
                    if( (board._pieces[0]->all.value >> i) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> i) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(i)};
                        res.push_back(mv);
                    }
                }
                index2 = index;
                for (int i = index%8+1 ; i < 8; i++){//horizontal move on right
                    index2++;
                    if( (board._pieces[0]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> index2) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                    }
                }
                index2 = index;
                for (int i = index%8 -1 ; i > -1; i--){//horizontal move on left
                    index2--;
                    if( (board._pieces[0]->all.value >> index2) & 1){
                        break;
                    }else if( (board._pieces[1]->all.value >> index2) & 1){
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                        break;
                    }else{
                        struct movement mv = {index , static_cast<uint8_t>(index2)};
                        res.push_back(mv);
                    }
                }
            }
        }
        return res;
    }

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