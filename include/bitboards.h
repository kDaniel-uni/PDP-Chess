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
        Black_pawns = (1<<55)+(1<<54)+(1<<53)+(1<<52)+(1<<51)+(1<<50)+(1<<49)+(1<<48);
        Black_rooks = (1<<63)+(1<<56);
        Black_knights = (1<<62)+(1<<57);
        Black_bishops = (1<<61)+(1<<58);
        Black_queen = (1<<59);
        Black_king = (1<<60);

        White_pawns = (1<<15)+(1<<14)+(1<<13)+(1<<12)+(1<<11)+(1<<10)+(1<<9)+(1<<8);
        White_rooks = (1<<7)+(1<<0);
        White_knights = (1<<6)+(1<<1);
        White_bishops = (1<<5)+(1<<2);
        White_queen = 1<<4;
        White_king = 1<<3;
    }

};

#endif //PDP_ECHEC_BITBOARDS_H
