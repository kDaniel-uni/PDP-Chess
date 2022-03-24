//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARDS_H
#define PDP_ECHEC_BITBOARDS_H

const int BOARD_SIZE = 64;

typedef uint64_t Bitboard;

struct Bitboards
{
    Bitboard pawns = 0;
   
    Bitboard rooks = 0;
    
    Bitboard knights = 0;

    Bitboard bishops = 0;
 
    Bitboard queen = 0;
   
    Bitboard king = 0;


    Bitboard all= 0;

    Bitboards(bool is_white,bool is_empty){
        if(is_empty){
            return;
        }
        if (is_white){
            pawns = (1<<15)+(1<<14)+(1<<13)+(1<<12)+(1<<11)+(1<<10)+(1<<9)+(1<<8);
            rooks = (1<<7)+(1<<0);
            knights = (1<<6)+(1<<1);
            bishops = (1<<5)+(1<<2);
            queen = 1<<4;
            king = 1<<3;
            return;
        }
        pawns = (1<<55)+(1<<54)+(1<<53)+(1<<52)+(1<<51)+(1<<50)+(1<<49)+(1<<48);
        rooks = (1<<63)+(1<<56);
        knights = (1<<62)+(1<<57);
        bishops = (1<<61)+(1<<58);
        queen = (1<<59);
        king = (1<<60);
    }

};

#endif //PDP_ECHEC_BITBOARDS_H
