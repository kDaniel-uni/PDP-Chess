//
// Pdp_chess university project
//

#include <string>
#include <array>
#include <iostream>
#include <cstring>
#include <math.h>
#include "board.h"

namespace pdp_chess {

    Board::Board() {
        pieces[black] = new PlayerState(black, true);
        pieces[white] = new PlayerState(white, true);
        updateWhiteAndBlackPieces();
        _moves_without_eating_counter = 0;
    }

    void Board::updateWhiteAndBlackPieces() {

        for (int i = 0; i < 2; i++) {
            pieces[i]->all.value = 0;
            for (auto bitboard : pieces[i]->list) {
                pieces[i]->all.value |= bitboard->value;
            }
        }
    }

    std::string Board::toString() const{
        std::string res;
        res.resize(64);

        for (int index = 0; index < BOARD_SIZE; index++) {
            res[index] = '-';
        }

        for (short color = 0; color < 2; color++) {
            for (Bitboard *bitboard : pieces[color]->list) {
                for (auto index : getPositionsV1(bitboard->value)) {
                    res[index] = bitboard->type;
                }
            }
        }

        return res;
    }

    void Board::fromString(const char *data) {

        resetToEmpty();

        for (auto index = 0; index < BOARD_SIZE; index++) {
            switch (data[index]) {
                case 'P':
                    pieces[white]->pawns.value += pow(2, index);
                    break;
                case 'p':
                    pieces[black]->pawns.value += pow(2, index);
                    break;
                case 'R':
                    pieces[white]->rooks.value += pow(2, index);
                    break;
                case 'r':
                    pieces[black]->rooks.value += pow(2, index);
                    break;
                case 'N':
                    pieces[white]->knights.value += pow(2, index);
                    break;
                case 'n':
                    pieces[black]->knights.value += pow(2, index);
                    break;
                case 'B':
                    pieces[white]->bishops.value += pow(2, index);
                    break;
                case 'b':
                    pieces[black]->bishops.value += pow(2, index);
                    break;
                case 'Q':
                    pieces[white]->queen.value += pow(2, index);
                    break;
                case 'q':
                    pieces[black]->queen.value += pow(2, index);
                    break;
                case 'K':
                    pieces[white]->king.value += pow(2, index);
                    break;
                case 'k':
                    pieces[black]->king.value += pow(2, index);
                    break;
                default:
                    break;
            }
        }
        updateWhiteAndBlackPieces();
    }

    void Board::doMove(Move move, bool is_main_loop) {
        if ((pieces[black]->all.value >> move.target_position) & 1) {
            eatPiece(move, *pieces[black]);

            if (is_main_loop){
                _moves_without_eating_counter = 0;
            }

        } else if ((pieces[white]->all.value >> move.target_position) & 1) {
            eatPiece(move, *pieces[white]);

            if (is_main_loop){
                _moves_without_eating_counter = 0;
            }

        } else {
            move.target_type = '-';

            if (is_main_loop){
                _moves_without_eating_counter ++;
            }
        }
        movePiece(move, *pieces[move.start_type < 90]);

        history.push_back(move);
    }

    Move Board::undoMove(bool is_main_loop) {
        Move move = history.back();
        Move reverse_move = {move.target_position, move.start_type, move.start_position, move.target_type};

        movePiece(reverse_move, *pieces[move.start_type < 90]);
        if (reverse_move.target_type == '-'){
            Move back = history.back();
            history.pop_back();
            if (is_main_loop){
                _moves_without_eating_counter --;
            }
            return back;
        }
        createPiece(move, *pieces[move.target_type < 90]);

        Move back = history.back();
        history.pop_back();
        return back;
    }

    bool Board::isDraw(){

        if (_moves_without_eating_counter > 50) {
            return true;
        }

        uint64_t all_white = pieces[white]->all.value;
        uint64_t all_black = pieces[black]->all.value;
        uint64_t king_white = pieces[white]->king.value;
        uint64_t king_black = pieces[black]->king.value;
        uint64_t bishops_white = pieces[white]->bishops.value;
        uint64_t bishops_black = pieces[black]->bishops.value;
        uint64_t knights_white = pieces[white]->knights.value;
        uint64_t knights_black = pieces[black]->knights.value;

        if((all_white == king_white) && (all_black == king_black)){ // if king vs king, the result is a draw
            return true;
        }

        if ((all_white == (king_white | bishops_white)) && (all_black == king_black)){
            return true;
        }

        if ((all_black == (king_black | bishops_black)) && (all_white == king_white)){
            return true;
        }

        if ((all_white == (king_white | knights_white)) && (all_black == king_black)){
            return true;
        }

        if ((all_black == (king_black | knights_black)) && (all_white == king_white)){
            return true;
        }

        if ((all_white == (king_white | bishops_white)) && (all_black == (king_black | bishops_black))){
            return true;
        }

        if(history.size() >= 8){
            Board historic_board = this->clone();

            historic_board.undoMove();
            historic_board.undoMove();
            historic_board.undoMove();
            historic_board.undoMove();

            if (!this->equal(historic_board)){
                return false;
            }

            historic_board.undoMove();
            historic_board.undoMove();
            historic_board.undoMove();
            historic_board.undoMove();

            return (this->equal(historic_board));
        }

        return false;
    }


    bool Board::isGameOver() {
        if ((pieces[black]->king.value == 0 || pieces[white]->king.value == 0 || Board::isDraw())){
            return true;
        }
        return false;
    }

    std::string Board::result() {
        if (pieces[black]->king.value == 0) {
            return "Game won by white";
        } else if (pieces[white]->king.value == 0) {
            return "Game won by black";
        } else {
            return "No winner";
        }
    }

    void Board::resetToClassic() {
        pieces[black]->setPlayerState(black, false);
        pieces[white]->setPlayerState(white, false);
        updateWhiteAndBlackPieces();
        history.clear();
        _moves_without_eating_counter = 0;
    }

    void Board::resetToEmpty() {
        pieces[black]->setPlayerState(black, true);
        pieces[white]->setPlayerState(white, true);
        updateWhiteAndBlackPieces();
        history.clear();
        _moves_without_eating_counter = 0;
    }

    void Board::draw() const {
        std::string chars = this->toString();

        std::cout << std::endl << "    a b c d e f g h" << std::endl << "   -----------------" << std::endl;
        for (int current_y = 7; current_y >= 0; current_y--){
            std::cout << current_y + 1 << " | ";
            for (int current_x = 0; current_x < 8; current_x++){
                std::cout << chars[current_y * 8 + current_x] << ' ';
            }
            std::cout << "| " << current_y + 1<< std::endl;
        }

        std::cout << "   -----------------" << std::endl << "    a b c d e f g h" << std::endl  << std::endl;
    }

    Board Board::clone(){ //return a copy of the current board
        Board clone = Board();
        std::string clonepiece = Board::toString();
        clone.fromString(clonepiece.c_str());
        std::vector<Move> clonehistory(history);
        clone.history = clonehistory;
        return clone;
    }

    bool Board::equal(const Board& board) {
        if (pieces[white]->equal(*board.pieces[white])
        && pieces[black]->equal(*board.pieces[black])){
            return true;
        }

        return false;
    }
}