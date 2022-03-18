
#include <string>
#include <array>
#include "board.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
using namespace bitboard_operation;
typedef uint64_t bitboard;

    struct
{
    bitboard White_pawns = 0;
    bitboard Black_pawns = 0;
    bitboard White_rooks = 0;
    bitboard Black_rooks = 0;
    bitboard White_knights = 0;
    bitboard Black_knights = 0;
    bitboard White_bishops = 0;
    bitboard Black_bishops = 0;
    bitboard White_queen = 0;
    bitboard Black_queen = 0;
    bitboard White_king = 0;
    bitboard Black_king = 0;

    bitboard White_pieces;
    bitboard Black_pieces;
}pieces;


std::string board::board_to_string(){
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
    return res;

}
void board::load_game(string filename){
    string line;
    ifstream input_file(filename);
    if (!input_file.is_open()) {// mettre le fichier par default donc grille de jeu simple
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return;
    }
    int pos = 64;
    int inc = 0;
    while(getline(input_file, line)){// faire attention aux coordonnées des cases : haut gauche = bitboard[56] 
        pos-=line.size();// verifier que pos passe pas en négatif. Voir si le size prend en compte le '\n'
        for (char const &c: line) {
            switch (c) {
                case 'P' : pieces.White_pawns += pow(2,(pos+inc));
                case 'p' : pieces.Black_pawns += pow(2,(pos+inc));

                case 'R' : pieces.White_rooks += pow(2,(pos+inc));
                case 'r' : pieces.Black_rooks += pow(2,(pos+inc));

                case 'N' : pieces.White_knights += pow(2,(pos+inc));
                case 'n' : pieces.Black_knights += pow(2,(pos+inc));

                case 'B' : pieces.White_bishops += pow(2,(pos+inc));
                case 'b' : pieces.Black_bishops += pow(2,(pos+inc));

                case 'Q' : pieces.White_queen += pow(2,(pos+inc));
                case 'q' : pieces.Black_queen += pow(2,(pos+inc));

                case 'K' : pieces.White_king += pow(2,(pos+inc));
                case 'k' : pieces.Black_king += pow(2,(pos+inc));


            }
            ++inc;
        }
        inc = 0;
    }
    input_file.close();
    upgrade_white_and_black_pieces();
    return;
}
















namespace bitboard_operation{

    std::string * bitboard_to_string(uint64_t * bitboard, string p){
        string * res;
        for(int i=0;i<sizeof(bitboard);i++){
            if(bitboard[i] = 0){
                res[i].append("-");
            }
            else{
                res[i].append(p);
            }
        }
        return res;
    }
    void upgrade_white_and_black_pieces(){
        pieces.White_pieces = pieces.White_pawns | pieces.White_rooks | pieces.White_knights | pieces.White_bishops | pieces.White_queen | pieces.White_king;
        pieces.Black_pieces = pieces.Black_pawns | pieces.Black_rooks | pieces.Black_knights | pieces.Black_bishops | pieces.Black_queen | pieces.Black_king;
    }




}