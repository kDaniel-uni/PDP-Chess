//
// Pdp_chess university project
//

#include "vector_shuffle.h"

namespace pdp_chess {

    /* Fisher-Yates shuffle
     */
    void moveShuffle(std::vector<Move>& moves){
        for (int index = 0; index < moves.size(); index ++){
            int insert_position = rand() % (index + 1);
            if (insert_position < index){
                std::swap(moves[index], moves[insert_position]);
            }
        }
    }

}