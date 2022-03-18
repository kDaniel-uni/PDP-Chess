//
// Pdp_echec university project
//

#include "../include/bitboard_operations.h"

namespace bitboard_operation {

    std::vector<uint8_t> get_positions(Bitboard bitboard) {
        std::vector<uint8_t> positions;
        for (int i = 0; i < 64; i++) {
            if ((bitboard >> i) & 1) {
                positions.push_back(i);
            }
        }
        return positions;
    }

    char* to_string(Bitboards* bitboards){
        char* res = new char[64];

        for (int index = 0; index < 64; index++){
            res[index] = '-';
        }

        for (auto index : get_positions(bitboards->White_pawns)){
            res[index] = 'P';
        }

        for (auto index : get_positions(bitboards->Black_pawns)){
            res[index] = 'p';
        }

        for (auto index : get_positions(bitboards->White_rooks)){
            res[index] = 'R';
        }

        for (auto index : get_positions(bitboards->Black_rooks)){
            res[index] = 'r';
        }

        for (auto index : get_positions(bitboards->White_knights)){
            res[index] = 'N';
        }

        for (auto index : get_positions(bitboards->Black_knights)){
            res[index] = 'n';
        }

        for (auto index : get_positions(bitboards->White_bishops)){
            res[index] = 'B';
        }

        for (auto index : get_positions(bitboards->Black_bishops)){
            res[index] = 'b';
        }

        for (auto index : get_positions(bitboards->White_queen)){
            res[index] = 'Q';
        }

        for (auto index : get_positions(bitboards->Black_queen)){
            res[index] = 'q';
        }

        for (auto index : get_positions(bitboards->White_king)){
            res[index] = 'K';
        }

        for (auto index : get_positions(bitboards->Black_king)){
            res[index] = 'k';
        }

        return res;
    }
}

