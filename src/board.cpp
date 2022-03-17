
#include <string>
#include <array>
#include "board.h"
using namespace std;
using namespace bitboard_operation;
typedef uint64_t bitboard;

    struct
{
    bitboard White_pawns;
    bitboard Black_pawns;
    bitboard White_rooks;
    bitboard Black_rooks;
    bitboard White_knights;
    bitboard Black_knights;
    bitboard White_bishops;
    bitboard Black_bishops;
    bitboard White_queen;
    bitboard Black_queen;
    bitboard White_king;
    bitboard Black_king;
}pieces;


std::string board_to_string(){
    string res;
    res.append(*bitboard_to_string(&pieces.White_pawns,"P"));
    res.append(*bitboard_to_string(&pieces.Black_pawns,"p"));
    res.append(*bitboard_to_string(&pieces.White_rooks,"R"));
    res.append(*bitboard_to_string(&pieces.Black_rooks,"r"));
    res.append(*bitboard_to_string(&pieces.White_knights,"N"));
    res.append(*bitboard_to_string(&pieces.Black_knights,"n"));
    res.append(*bitboard_to_string(&pieces.White_bishops,"B"));
    res.append(*bitboard_to_string(&pieces.Black_bishops,"b"));
    res.append(*bitboard_to_string(&pieces.White_queen,"Q"));
    res.append(*bitboard_to_string(&pieces.Black_queen,"q"));
    res.append(*bitboard_to_string(&pieces.White_king,"K"));
    res.append(*bitboard_to_string(&pieces.Black_king,"k"));

}









namespace bitboard_operation{

    std::string * bitboard_to_string(uint64_t * bitboard, string p){
        string * res;
        for(int i=0;i<sizeof(bitboard);i++){
            if(bitboard[i] = 0){
                res[i].append(".");
            }
            else{
                res[i].append(p);
            }
        }
        return res;
    }




}