//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_HEURISTIC_H
#define PDP_ECHEC_HEURISTIC_H

namespace pdp_chess {

    class Heuristic {
    public :
        int pawns_value;
        int rooks_value;
        int bishops_value;
        int knights_value;
        int queen_value;
        int king_value;

        Heuristic(int p_v, int r_v, int b_v, int kn_v, int q_v, int k_v) {
            pawns_value = p_v;
            rooks_value = r_v;
            bishops_value = b_v;
            knights_value = kn_v;
            queen_value = q_v;
            king_value = k_v;
        };
    };

}

#endif //PDP_ECHEC_HEURISTIC_H