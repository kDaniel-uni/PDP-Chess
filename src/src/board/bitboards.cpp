//
// Pdp_chess university project
//

#include "stdint.h"
#include "bitboards.h"

namespace pdp_chess {

    Bitboards::Bitboards(bool is_white, bool is_empty){

        pawns.type = (char) ('p' - (is_white * 32));
        rooks.type = (char) ('r' - (is_white * 32));
        knights.type = (char) ('n' - (is_white * 32));
        bishops.type = (char) ('b' - (is_white * 32));
        queen.type = (char) ('q' - (is_white * 32));
        king.type = (char) ('k' - (is_white * 32));

        if (is_empty) {
            pawns.value = 0;
            rooks.value = 0;
            knights.value = 0;
            bishops.value = 0;
            queen.value = 0;
            king.value = 0;

            list[0] = &pawns;
            list[1] = &rooks;
            list[2] = &knights;
            list[3] = &bishops;
            list[4] = &queen;
            list[5] = &king;

            return;
        }

        if (is_white) {
            pawns.value =
                    (1 << 15) + (1 << 14) + (1 << 13) + (1 << 12) + (1 << 11) + (1 << 10) + (1 << 9) + (1 << 8);
            rooks.value = (1 << 7) + (1 << 0);
            knights.value = (1 << 6) + (1 << 1);
            bishops.value = (1 << 5) + (1 << 2);
            queen.value = 1 << 3;
            king.value = 1 << 4;

            list[0] = &pawns;
            list[1] = &rooks;
            list[2] = &knights;
            list[3] = &bishops;
            list[4] = &queen;
            list[5] = &king;

            return;
        }

        uint64_t base = 1; // prevent shift max size warning

        pawns.value = (base << 55) + (base << 54) + (base << 53) + (base << 52) + (base << 51) + (base << 50) +
                (base << 49) + (base << 48);
        rooks.value = (base << 63) + (base << 56);
        knights.value = (base << 62) + (base << 57);
        bishops.value = (base << 61) + (base << 58);
        queen.value = (base << 59);
        king.value = (base << 60);

        list[0] = &pawns;
        list[1] = &rooks;
        list[2] = &knights;
        list[3] = &bishops;
        list[4] = &queen;
        list[5] = &king;
    }

    int Bitboards::getBitboardValue(Heuristic *h) {
        int value = 0;
        for (int i = 0; i < 6; i++) {
            Bitboard* b = list[i];
            for (int j = 0; j < BOARD_SIZE; j++) {
                if ((b->value >> j) & 1) {
                    if (i == 0)
                        value += h->pawns_value;
                    if (i == 1)
                        value += h->rooks_value;
                    if (i == 2)
                        value += h->bishops_value;
                    if (i == 3)
                        value += h->knights_value;
                    if (i == 4)
                        value += h->queen_value;
                    if (i == 5)
                        value += h->king_value;
                }
            }
        }
        return value;
    }

}