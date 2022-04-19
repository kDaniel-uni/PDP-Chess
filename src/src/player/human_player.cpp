//
// Pdp_chess university project
//

#include "human_player.h"
#include <iostream>
using namespace std;

namespace pdp_chess {

    HumanPlayer::HumanPlayer(LegalMove &legal_move) {
        _legal_move = &legal_move;
        initMoveMap();
    }

    Move HumanPlayer::askNextMove(Board &board, color current_color) {
        board.draw();
        cout << "List of legal move : " <<  endl;
        char input[5];
        Move m;
        bool valid_move = false;
        auto moves = _legal_move->GetLegalMoves(board, current_color);
        // print of possible moves
        for (Move movement : moves){
            cout <<  _move_map[movement.start_position] <<  _move_map[movement.target_position] << endl;
        }
        while( !valid_move){
            cout << "Choose a move to play : " << endl;
            cin.getline(input,5);

            
            m = moveFromString(input);
            for(Move mv : moves){
                if ((m.start_position == mv.start_position) && (m.target_position == mv.target_position)){
                    m.start_type = mv.start_type;
                    valid_move = true;
                    return m;
                }
            }
            cout<< " it is not a valid move" <<endl;
        }
        return m;
    }

    void HumanPlayer::initMoveMap(){
        char tmp = 'a';
        int index = 0;
        for( int x = 0 ; x<8; x++){
            for(int y = 0; y<8;y++){
                _move_map[index]= string(tmp + to_string(x+1));
                index++;
                tmp= (char)tmp +1;
            }
            tmp = 'a';
            
        }
    }
    Move HumanPlayer::moveFromString(string mv){

        string start = mv.substr(0,2);
        string target = mv.substr(2);
        
        Move move;
        for(int i = 0; i<64; i++){
            if(start == _move_map[i]){
                move.start_position = i;
            }
            if(target == _move_map[i]){
                move.target_position = i;
            }
        }
        return move;
        
    }

}
