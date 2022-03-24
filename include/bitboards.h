//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_BITBOARDS_H
#define PDP_ECHEC_BITBOARDS_H

const int BOARD_SIZE = 64;

struct Bitboard{
    uint64_t value;
    char type;
};

struct Bitboards
{
    Bitboard pawns;
   
    Bitboard rooks;
    
    Bitboard knights;

    Bitboard bishops;
 
    Bitboard queen;
   
    Bitboard king;

    Bitboard all;

    Bitboard* list[6] = { &pawns, &rooks, &knights, &bishops, &queen, &king };

    Bitboards(bool is_white, bool is_empty){
        
        pawns.type = (char)('p' - (is_white * 32));
        rooks.type = (char)('r' - (is_white * 32));
        knights.type = (char)('n' - (is_white * 32));
        bishops.type = (char)('b' - (is_white * 32));
        queen.type = (char)('q' - (is_white * 32));
        king.type = (char)('k' - (is_white * 32));
        
        if(is_empty){
            pawns.value = 0;
            rooks.value = 0;
            knights.value = 0;
            bishops.value = 0;
            queen.value = 0;
            king.value = 0;
            return;
        }

        if (is_white){
            pawns.value = (1<<15) + (1<<14) + (1<<13) + (1<<12) + (1<<11) + (1<<10) + (1<<9) + (1<<8);
            rooks.value = (1 << 7) + (1 << 0);
            knights.value = (1 << 6) + (1 << 1);
            bishops.value = (1 << 5) + (1 << 2);
            queen.value = 1 << 3;
            king.value = 1 << 4;
            return;
        }
        
        uint64_t base = 1; // prevent shift max size warning
        
        pawns.value = (base<<55) + (base<<54) + (base<<53) + (base<<52) + (base<<51) + (base<<50) + (base<<49) + (base<<48);
        rooks.value= (base << 63) + (base << 56);
        knights.value = (base << 62) + (base << 57);
        bishops.value = (base << 61) + (base << 58);
        queen.value = (base << 59);
        king.value = (base << 60);
    }
};

#endif //PDP_ECHEC_BITBOARDS_H
