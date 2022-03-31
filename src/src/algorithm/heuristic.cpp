//
// Pdp_chess university project
//


#include <heuristic.h>

namespace pdp_chess {

    Heuristic::Heuristic(int p_v, int r_v, int b_v, int kn_v, int q_v, int k_v) {
        pawns_value = p_v;
        rooks_value = r_v;
        bishops_value = b_v;
        knights_value = kn_v;
        queen_value = q_v;
        king_value = k_v;
    }


    int Heuristic::evaluateBoard(const Board &board) {
        return 0;
    }
}
