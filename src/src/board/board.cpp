//
// Pdp_chess university project
//

#include <string>
#include <array>
#include <iostream>
#include <cstring>
#include <math.h>
#include "board.h"
#include "bitboard_operations.h"

namespace pdp_chess {

    Board::Board() {
        _pieces[black] = new PlayerState(black, true);
        _pieces[white] = new PlayerState(white, true);
        updateWhiteAndBlackPieces();
    }

    void Board::updateWhiteAndBlackPieces() {

        for (int i = 0; i < 2; i++) {
            _pieces[i]->all.value = 0;
            for (auto bitboard : _pieces[i]->list) {
                _pieces[i]->all.value |= bitboard->value;
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
            for (Bitboard *bitboard : _pieces[color]->list) {
                for (auto index : getPositions(*bitboard)) {
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
                    _pieces[white]->pawns.value += pow(2, index);
                    break;
                case 'p':
                    _pieces[black]->pawns.value += pow(2, index);
                    break;
                case 'R':
                    _pieces[white]->rooks.value += pow(2, index);
                    break;
                case 'r':
                    _pieces[black]->rooks.value += pow(2, index);
                    break;
                case 'N':
                    _pieces[white]->knights.value += pow(2, index);
                    break;
                case 'n':
                    _pieces[black]->knights.value += pow(2, index);
                    break;
                case 'B':
                    _pieces[white]->bishops.value += pow(2, index);
                    break;
                case 'b':
                    _pieces[black]->bishops.value += pow(2, index);
                    break;
                case 'Q':
                    _pieces[white]->queen.value += pow(2, index);
                    break;
                case 'q':
                    _pieces[black]->queen.value += pow(2, index);
                    break;
                case 'K':
                    _pieces[white]->king.value += pow(2, index);
                    break;
                case 'k':
                    _pieces[black]->king.value += pow(2, index);
                    break;
                default:
                    break;
            }
        }
        updateWhiteAndBlackPieces();
    }

    void Board::doMove(Move move) {
        if ((_pieces[black]->all.value >> move.target_position) & 1) {
            eatPiece(move, *_pieces[black]);
        } else if ((_pieces[white]->all.value >> move.target_position) & 1) {
            eatPiece(move, *_pieces[white]);
        } else {
            move.target_type = '-';
        }
        movePiece(move, *_pieces[move.start_type < 90]);

        _history.push_back(move);
    }

    Move Board::undoMove() {
        Move move = _history.back();
        Move reverse_move = {move.target_position, move.start_type, move.start_position, move.target_type};

        movePiece(reverse_move, *_pieces[move.start_type < 90]);
        if (reverse_move.target_type == '-'){
            Move back = _history.back();
            _history.pop_back();
            return back;
        }
        createPiece(move, *_pieces[move.target_type < 90]);

        Move back = _history.back();
        _history.pop_back();
        return back;
    }

    bool Board::isDraw(){
        /*if(_legal_move.legalMove(*this,white).size() == 0 || _legal_move.legalMove(*this,black).size() == 0){ //verify blocked board
            return true;  WIP need to have LegalMove in Board to uncomment
        }*/

        uint64_t all_white = _pieces[white]->all.value;
        uint64_t all_black = _pieces[black]->all.value;
        uint64_t king_white = _pieces[white]->king.value;
        uint64_t king_black = _pieces[black]->king.value;
        uint64_t bishops_white = _pieces[white]->bishops.value;
        uint64_t bishops_black = _pieces[black]->bishops.value;
        uint64_t knights_white = _pieces[white]->knights.value;
        uint64_t knights_black = _pieces[black]->knights.value;

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

        if(_history.size() >= 8){
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
        if ((_pieces[black]->king.value == 0 || _pieces[white]->king.value == 0 || Board::isDraw())){
            return true;
        }
        return false;
    }

    std::string Board::result() {
        if (_pieces[black]->king.value == 0) {
            return "Game won by white";
        } else if (_pieces[white]->king.value == 0) {
            return "Game won by black";
        } else {
            return "No winner";
        }
    }

    void Board::resetToClassic() {
        _pieces[black]->setPlayerState(black, false);
        _pieces[white]->setPlayerState(white, false);
        updateWhiteAndBlackPieces();
        _history.clear();
    }

    void Board::resetToEmpty() {
        _pieces[black]->setPlayerState(black, true);
        _pieces[white]->setPlayerState(white, true);
        updateWhiteAndBlackPieces();
        _history.clear();
    }

    int Board::getColor(int index) {
        for (int color = 0; color < 2; color++) {
            if ((_pieces[color]->all.value >> index) & 1) {
                return color;
            }
        }
        return -1;
    }

    char Board::findType(uint8_t index) const{

        if ((_pieces[white]->all.value >> index) & 1){
            for (Bitboard* bitboard : _pieces[white]->list){
                if ((bitboard->value >> index) & 1){
                    return bitboard->type;
                }
            }
        }

        if ((_pieces[black]->all.value >> index) & 1){
            for (Bitboard* bitboard : _pieces[black]->list){
                if ((bitboard->value >> index) & 1){
                    return bitboard->type;
                }
            }
        }

        return '-';
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
        std::vector<Move> clonehistory(_history);
        clone._history = clonehistory;
        return clone;
    }

    bool Board::equal(Board& board) {
        if (_pieces[white]->equal(*board._pieces[white])
        && _pieces[black]->equal(*board._pieces[black])){
            return true;
        }

        return false;
    }
}