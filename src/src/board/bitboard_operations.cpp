//
// Pdp_echec university project
//

#include "bitboard_operations.h"
#include <algorithm>

namespace pdp_chess {

    std::vector<uint8_t> getPositions(const Bitboard& bitboard) {
        std::vector<uint8_t> positions;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((bitboard.value >> i) & 1) {
                positions.push_back(i);
            }
        }
        return positions;
    }


    void eatPiece(uint8_t index, Bitboards& bitboards){
        uint64_t base = 1;
        uint64_t mask = base<<index;
        for(auto pos : getPositions(bitboards.pawns)){
            if (pos == index){
                bitboards.pawns.value = bitboards.pawns.value ^= mask;
                return ;
            }
        }
        for(auto pos : getPositions(bitboards.bishops)){
            if (pos == index){
                bitboards.bishops.value = bitboards.bishops.value ^= mask;
                return ;
            }
        }
        for(auto pos : getPositions(bitboards.king)){
            if (pos == index){
                bitboards.king.value = bitboards.king.value ^= mask;
                return ;
            }
        }
        for(auto pos : getPositions(bitboards.knights)){
            if (pos == index){
                bitboards.knights.value = bitboards.knights.value ^= mask;
                return ;
            }
        }
        for(auto pos : getPositions(bitboards.queen)){
            if (pos == index){
                bitboards.queen.value = bitboards.queen.value ^= mask;
                return ;
            }
        }
        for(auto pos : getPositions(bitboards.rooks)){
            if (pos == index){
                bitboards.rooks.value = bitboards.rooks.value ^= mask;
                return ;
            }
        }
    }

    void movePiece(uint64_t mask, Bitboard& bitboard){
        bitboard.value = bitboard.value ^= mask;
    }

    uint64_t getWhitePawnsInBasePosition(const Bitboard& bitboard){
        uint64_t white_pawn_base_position = (1<<15) + (1<<14) + (1<<13) + (1<<12) + (1<<11) + (1<<10) + (1<<9) + (1<<8);
        return bitboard.value & white_pawn_base_position;
    }

    uint64_t getBlackPawnsInBasePosition(const Bitboard& bitboard){
        uint64_t base = 1;
        uint64_t black_pawn_base_position = (base<<55) + (base<<54) + (base<<53) + (base<<52) + (base<<51) + (base<<50) + (base<<49) + (base<<48);
        return bitboard.value & black_pawn_base_position;
    }

}

