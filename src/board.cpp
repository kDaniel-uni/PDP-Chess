//
// Pdp_echec university project
//

#include <string>
#include <array>
#include "../include/board.h"
#include <iostream>
#include <fstream>
#include "../include/bitboard_operations.h"

using namespace std;

board::board(){
    _bitboards = new Bitboards();
}

void board::upgrade_white_and_black_pieces(){
    _bitboards->White_pieces = _bitboards->White_pawns | _bitboards->White_rooks | _bitboards->White_knights | _bitboards->White_bishops | _bitboards->White_queen | _bitboards->White_king;
    _bitboards->Black_pieces = _bitboards->Black_pawns | _bitboards->Black_rooks | _bitboards->Black_knights | _bitboards->Black_bishops | _bitboards->Black_queen | _bitboards->Black_king;
}

char* board::board_to_string(){
    return bitboard_operation::to_string(_bitboards);
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
                case 'P' : _bitboards->White_pawns += pow(2,(pos+inc));
                case 'p' : _bitboards->Black_pawns += pow(2,(pos+inc));

                case 'R' : _bitboards->White_rooks += pow(2,(pos+inc));
                case 'r' : _bitboards->Black_rooks += pow(2,(pos+inc));

                case 'N' : _bitboards->White_knights += pow(2,(pos+inc));
                case 'n' : _bitboards->Black_knights += pow(2,(pos+inc));

                case 'B' : _bitboards->White_bishops += pow(2,(pos+inc));
                case 'b' : _bitboards->Black_bishops += pow(2,(pos+inc));

                case 'Q' : _bitboards->White_queen += pow(2,(pos+inc));
                case 'q' : _bitboards->Black_queen += pow(2,(pos+inc));

                case 'K' : _bitboards->White_king += pow(2,(pos+inc));
                case 'k' : _bitboards->Black_king += pow(2,(pos+inc));


            }
            ++inc;
        }
        inc = 0;
    }
    input_file.close();
    upgrade_white_and_black_pieces();
    return;
}