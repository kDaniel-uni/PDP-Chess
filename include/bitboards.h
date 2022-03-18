//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARDS_H
#define PDP_ECHEC_BITBOARDS_H

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

    Bitboards(){
        White_pawns = 65280;
        White_rooks = 129;
        White_knights = 66;
        White_bishops = 36;
        White_queen = 16;
        White_king = 8;
    }

};

#endif //PDP_ECHEC_BITBOARDS_H
