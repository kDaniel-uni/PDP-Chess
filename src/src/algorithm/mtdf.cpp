//
// Pdp_chess university project
//

#include "mtdf.h"

namespace pdp_chess {


        Move findNextMove(Board& board, color current_color){
            
        }

        std::string getParameters(){

        }

        int mtdf(Board board, int f, int depth){
            int value = f;
            int beta = 0;
            int upperBound = std::numeric_limits<int>::max();
            int lowerBound = std::numeric_limits<int>::min();
            while(lowerBound < upperBound){
                if(value = lowerBound){
                    beta = g + 1:
                }
                else{
                    beta = value;
                }
                //value = AlphaBetaWithMemory(board, beta-1, beta, depth);
                if(value < beta){
                    upperBound = value;
                }
                else{
                    lowerBound = value;
                }
            }
            return value;
        }
    };

}