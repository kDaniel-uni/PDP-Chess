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

        std::cout << std::endl << "    a b c d e f g h" << std::endl << "   -----------------" << std::endl;
        for (int current_y = 7; current_y >= 0; current_y--){
            std::cout << current_y + 1 << " | ";
            for (int current_x = 0; current_x < 8; current_x++){
                std::cout << chars[current_y * 8 + current_x] << ' ';
            }
            std::cout << "| " << current_y + 1<< std::endl;
        }

        std::cout << "   -----------------" << std::endl << "    a b c d e f g h" << std::endl  << std::endl;
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

