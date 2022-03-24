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

        for (auto index : get_positions(bitboards[0].pawns)) {
            res[index] = 'P';
        }

        for (auto index : get_positions(bitboards[1].pawns)) {
            res[index] = 'p';
        }

        for (auto index : get_positions(bitboards[0].rooks)) {
            res[index] = 'R';
        }

        for (auto index : get_positions(bitboards[1].rooks)) {
            res[index] = 'r';
        }

        for (auto index : get_positions(bitboards[0].knights)) {
            res[index] = 'N';
        }

        for (auto index : get_positions(bitboards[1].knights)) {
            res[index] = 'n';
        }

        for (auto index : get_positions(bitboards[0].bishops)) {
            res[index] = 'B';
        }

        for (auto index : get_positions(bitboards[1].bishops)) {
            res[index] = 'b';
        }

        for (auto index : get_positions(bitboards[0].queen)) {
            res[index] = 'Q';
        }

        for (auto index : get_positions(bitboards[1].queen)) {
            res[index] = 'q';
        }

        for (auto index : get_positions(bitboards[0].king)) {
            res[index] = 'K';
        }

        for (auto index : get_positions(bitboards[1].king)) {
            res[index] = 'k';
        }

        return res;
    }

    
    Bitboards * from_string(const char *data) {
        Bitboards *bitboards[2];
        bitboards[0] = new Bitboards(true,true);
        bitboards[1] = new Bitboards(false,true);
        for (auto index = 0; index < BOARD_SIZE; index++) {
            switch (data[index]) {
                case 'P':
                    bitboards[0]->pawns += pow(2, index);
                    break;
                case 'p':
                    bitboards[1]->pawns += pow(2, index);
                    break;
                case 'R':
                    bitboards[0]->rooks += pow(2, index);
                    break;
                case 'r':
                    bitboards[1]->rooks += pow(2, index);
                    break;
                case 'N':
                    bitboards[0]->knights += pow(2, index);
                    break;
                case 'n':
                    bitboards[1]->knights += pow(2, index);
                    break;
                case 'B':
                    bitboards[0]->bishops += pow(2, index);
                    break;
                case 'b':
                    bitboards[1]->bishops += pow(2, index);
                    break;
                case 'Q':
                    bitboards[0]->queen += pow(2, index);
                    break;
                case 'q':
                    bitboards[1]->queen += pow(2, index);
                    break;
                case 'K':
                    bitboards[0]->king += pow(2, index);
                    break;
                case 'k':
                    bitboards[1]->king += pow(2, index);
                    break;
                default:
                    break;
            }
        }
        return *bitboards;
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

