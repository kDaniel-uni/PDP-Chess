#ifndef PDP_CHESS_LEGAL_MOVE_V2_H
#define PDP_CHESS_LEGAL_MOVE_V2_H



#include <cstdint>
#include "bitboards.h"
#include <iostream>
#include <vector>
#include "board.h"
#include "move.h"

namespace pdp_chess {
        
    class LegalMove{
        private:
            uint64_t _pawns_attacks_table[2][64];
            uint64_t _pawns_moves_table[2][64];
            uint64_t _knights_moves_table[64];
            uint64_t _kings_moves_table[64];
        
            uint64_t const _not_a_border = 18374403900871474942ULL;
            uint64_t const _not_h_border = 9187201950435737471ULL;
            uint64_t const _not_ab_border = 18229723555195321596ULL;
            uint64_t const _not_gh_border = 4557430888798830399ULL;

            uint64_t pawnsAttacks(int color, int position); // color {black = 0 ; white = 1}
            uint64_t pawnsMoves(int color, int position);
            uint64_t knightsMoves(int position);
            uint64_t kingsMoves(int position);
            uint64_t rooksMoves(int position, const Board& board, bool color);
            uint64_t bishopsMoves(int position, const Board& board, bool color);
            uint64_t queensMoves(int position, const Board& board, bool color);

            void pawnsLegalMoves(const Board& board, bool color, std::vector<Move>& moves);
            void kingLegalMoves(const Board& board, bool color, std::vector<Move>& moves);
            void knightsLegalMoves(const Board& board, bool color, std::vector<Move>& moves);
            void bishopsLegalMoves(const Board& board, bool color, std::vector<Move>& moves);
            void queensLegalMoves(const Board& board, bool color, std::vector<Move>& moves);
            void rooksLegalMoves(const Board& board, bool color, std::vector<Move>& moves);

            void initLookupTable();

            std::string bitboardToString(uint64_t mask);// for a debug usage
            void printBitboard(uint64_t mask); // for a debug usage

        public:
            LegalMove();
            std::vector<Move> legalMove(const Board& board, bool white);
    };
}

#endif //PDP_CHESS_LEGAL_MOVE_V2_H