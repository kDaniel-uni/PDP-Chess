//
// Pdp_echec university project
//

#include "../include/bitboard_operations.h"
#include <algorithm>
#include <iostream>
#include <math.h>

namespace io_bitboard {

    std::vector<uint8_t> get_positions(Bitboard bitboard) {
        std::vector<uint8_t> positions;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((bitboard >> i) & 1) {
                positions.push_back(i);
            }
        }
        return positions;
    }

    std::string to_string(Bitboards *bitboards) {
        std::string res;
        res.resize(64);

        for (int index = 0; index < BOARD_SIZE; index++) {
            res[index] = '-';
        }

        for (auto index : get_positions(bitboards->White_pawns)) {
            res[index] = 'P';
        }

        for (auto index : get_positions(bitboards->Black_pawns)) {
            res[index] = 'p';
        }

        for (auto index : get_positions(bitboards->White_rooks)) {
            res[index] = 'R';
        }

        for (auto index : get_positions(bitboards->Black_rooks)) {
            res[index] = 'r';
        }

        for (auto index : get_positions(bitboards->White_knights)) {
            res[index] = 'N';
        }

        for (auto index : get_positions(bitboards->Black_knights)) {
            res[index] = 'n';
        }

        for (auto index : get_positions(bitboards->White_bishops)) {
            res[index] = 'B';
        }

        for (auto index : get_positions(bitboards->Black_bishops)) {
            res[index] = 'b';
        }

        for (auto index : get_positions(bitboards->White_queen)) {
            res[index] = 'Q';
        }

        for (auto index : get_positions(bitboards->Black_queen)) {
            res[index] = 'q';
        }

        for (auto index : get_positions(bitboards->White_king)) {
            res[index] = 'K';
        }

        for (auto index : get_positions(bitboards->Black_king)) {
            res[index] = 'k';
        }

        return res;
    }


    Bitboards *from_string(const char *data) {
        Bitboards *bitboards = new Bitboards(true);
        for (auto index = 0; index < BOARD_SIZE; index++) {
            switch (data[index]) {
                case 'P':
                    bitboards->White_pawns += pow(2, index);
                    break;
                case 'p':
                    bitboards->Black_pawns += pow(2, index);
                    break;
                case 'R':
                    bitboards->White_rooks += pow(2, index);
                    break;
                case 'r':
                    bitboards->Black_rooks += pow(2, index);
                    break;
                case 'N':
                    bitboards->White_knights += pow(2, index);
                    break;
                case 'n':
                    bitboards->Black_knights += pow(2, index);
                    break;
                case 'B':
                    bitboards->White_bishops += pow(2, index);
                    break;
                case 'b':
                    bitboards->Black_bishops += pow(2, index);
                    break;
                case 'Q':
                    bitboards->White_queen += pow(2, index);
                    break;
                case 'q':
                    bitboards->Black_queen += pow(2, index);
                    break;
                case 'K':
                    bitboards->White_king += pow(2, index);
                    break;
                case 'k':
                    bitboards->Black_king += pow(2, index);
                    break;
                default:
                    break;
            }
        }
        return bitboards;
    }

    void draw_board(Bitboards* bitboards){
        std::string chars = io_bitboard::to_string(bitboards);
        int char_in_row = 0;
        for (int index = 0; index < BOARD_SIZE; index++) {
            if (char_in_row >= 8){
                std::cout << std::endl;
                char_in_row = 0;
            }
            std::cout << chars[index] << ' ';
            char_in_row ++;
        }
        std::cout << std::endl << std::endl;
    }

    Bitboard get_bitboard_to_index(Bitboards* bitboards, int index){

        for (auto i : get_positions(bitboards->White_pawns)) {
            if (i == index){
                return bitboards->White_pawns;
            }
        }

        for (auto i : get_positions(bitboards->Black_pawns)) {
            if (i == index){
                return bitboards->Black_pawns;
            }
        }

        for (auto i : get_positions(bitboards->White_rooks)) {
            if (i == index){
                return bitboards->White_rooks;
            }
        }

        for (auto i : get_positions(bitboards->Black_rooks)) {
            if (i == index){
                return bitboards->Black_rooks;
            }
        }

        for (auto i : get_positions(bitboards->White_knights)) {
           if (i == index){
                return bitboards->White_knights;
            }
        }

        for (auto i : get_positions(bitboards->Black_knights)) {
            if (i == index){
                return bitboards->Black_knights;
            }
        }

        for (auto i : get_positions(bitboards->White_bishops)) {
            if (i == index){
                return bitboards->White_bishops;
            }
        }

        for (auto i : get_positions(bitboards->Black_bishops)) {
            if (i == index){
                return bitboards->Black_bishops;
            }
        }

        for (auto i : get_positions(bitboards->White_queen)) {
            if (i == index){
                return bitboards->White_queen;
            }
        }

        for (auto i : get_positions(bitboards->Black_queen)) {
            if (i == index){
                return bitboards->Black_queen;
            }
        }

        for (auto i : get_positions(bitboards->White_king)) {
            if (i == index){
                return bitboards->White_king;
            }
        }

        for (auto i : get_positions(bitboards->Black_king)) {
            if (i == index){
                return bitboards->Black_king;
            }
        }
    }

    Bitboards * traduct_from_move(Bitboards * bitboards,move mv){
        int begin_bit = ((int)mv.moving_position[0] - 49) * (int)mv.moving_position[1];
        int end_bit = ((int)mv.target_position[0] - 49) * (int)mv.target_position[1];
        Bitboard to_move = get_bitboard_to_index(bitboards,begin_bit);
        to_move += pow(2,end_bit);
        bitboards->White_pawns += pow(2,16); // test 
        bitboards->White_pawns >> begin_bit;
        return bitboards;
    }
}

namespace filters{

    Bitboard get_white_pawns_in_base_position(Bitboard bitboard){
        Bitboard white_pawn_base_position = 71776119061217280;
        return bitboard & white_pawn_base_position;
    }

    Bitboard get_black_pawns_in_base_position(Bitboard bitboard){
        Bitboard black_pawn_base_position = 65280;
        return bitboard & black_pawn_base_position;
    }

}

