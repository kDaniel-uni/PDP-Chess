//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARDS_H
#define PDP_ECHEC_BITBOARDS_H

const int BOARD_SIZE = 64;

typedef uint64_t Bitboard;

struct Bitboards
{
    Bitboard White_pawns = 0;
    Bitboard Black_pawns = 0;
    Bitboard White_rooks = 0;
    Bitboard Black_rooks = 0;
    Bitboard White_knights = 0;
    Bitboard Black_knights = 0;
    Bitboard White_bishops = 0;
    Bitboard Black_bishops = 0;
    Bitboard White_queen = 0;
    Bitboard Black_queen = 0;
    Bitboard White_king = 0;
    Bitboard Black_king = 0;

    Bitboard White_pieces;
    Bitboard Black_pieces;

    Bitboards(bool is_empty){
        if (is_empty){
            return;
        }
        White_pawns = 65280;
        White_rooks = 129;
        White_knights = 66;
        White_bishops = 36;
        White_queen = 16;
        White_king = 8;

        Black_pawns = 71776119061217280;
        Black_rooks = 9295429630892703744;
        Black_knights = 4755801206503243776;
        Black_bishops = 2594073385365405696;
        Black_queen = 576460752303423488;
        Black_king = 1152921504606846976;
    }

};

#endif //PDP_ECHEC_BITBOARDS_H
