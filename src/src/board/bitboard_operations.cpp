//
// Pdp_chess university project
//

#include "bitboard_operations.h"
#include <algorithm>
#include <math.h>

namespace pdp_chess {

    std::vector<uint8_t> getPositions(uint64_t bitboard) {
        std::vector<uint8_t> positions;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((bitboard >> i) & 1) {
                positions.emplace_back(i);
            }
        }
        return positions;
    }

    std::vector<uint8_t> getPositionsV2(uint64_t bitboard) {
        std::vector<uint8_t> positions;
        uint64_t onebit;
        while (bitboard != 0){
            onebit = bitboard & -bitboard;
            positions.emplace_back(log2(onebit)); // log2 is O(1)
            bitboard -= onebit;
        }
        return positions;
    }

    void eatPiece(Move& move, PlayerState& player_state){
        uint64_t base = 1;
        uint64_t mask = base << move.target_position;

        for (auto bitboard : player_state.list){
            if ((bitboard->value >> move.target_position) & 1){
                bitboard->value ^= mask;
                player_state.all.value ^= mask;
                move.target_type = bitboard->type;
                return;
            }
        }
    }

    void movePiece(Move& move, PlayerState& player_state){
        uint64_t base = 1;
        uint64_t mask = (base << move.start_position) + (base << move.target_position);

        for (auto& bitboard : player_state.list){
            if (bitboard->type == move.start_type){
                bitboard->value ^= mask;
                player_state.all.value ^= mask;
                return;
            }
        }
    }

    void createPiece(Move& move, PlayerState& player_state){
        uint64_t base = 1;
        uint64_t mask = (base << move.target_position);

        for (auto& bitboard : player_state.list){
            if (bitboard->type == move.target_type){
                bitboard->value |= mask;
                player_state.all.value |= mask;
                return;
            }
        }

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

