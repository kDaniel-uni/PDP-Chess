
#include "legal_move_v2.h"
#include "bitboard_operations.h"
#include <math.h>

namespace pdp_chess {

    LegalMove::LegalMove(){
        initLookupTable();
    }

    uint64_t LegalMove::pawnsMoves(int color, int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if(color){
            if( (position > 7) & (position < 16) ){
                mask |= (bitboard << 16);
            }
            mask |= (bitboard << 8);
        }

        else{
            if( (position > 47) & (position < 56) ){
                mask |= (bitboard >> 16);
            }
            mask |= (bitboard >> 8);
        }

        return mask;
    }

    uint64_t LegalMove::pawnsAttacks(int color, int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if(color){
            if((bitboard << 7) & _not_h_border){
                mask |= (bitboard << 7);
            }
            if((bitboard << 9) & _not_a_border){
                mask |= (bitboard << 9);
            }
        }

        else{
            if((bitboard >> 7) & _not_a_border){
                mask |= (bitboard >> 7);
            }
            if((bitboard >> 9) & _not_h_border){
                mask |= (bitboard >> 9);
            }
        }

        return mask;
    }

    uint64_t LegalMove::knightsMoves(int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if( (bitboard >> 17) & _not_h_border){
            mask |= (bitboard >> 17);
        }
        if( (bitboard >> 15) & _not_a_border){
            mask |= (bitboard >> 15);
        }
        if( (bitboard >> 10) & _not_gh_border){
            mask |= (bitboard >> 10);
        }
        if( (bitboard >> 6) & _not_ab_border){
            mask |= (bitboard >> 6);
        }

        if( (bitboard << 17) & _not_a_border){
            mask |= (bitboard << 17);
        }
        if( (bitboard << 15) & _not_h_border){
            mask |= (bitboard << 15);
        }
        if( (bitboard << 10) & _not_ab_border){
            mask |= (bitboard << 10);
        }
        if( (bitboard << 6) & _not_gh_border){
            mask |= (bitboard << 6);
        }

        return mask;
    }
    uint64_t LegalMove::kingsMoves(int position){
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if((bitboard << 7) & _not_h_border){
            mask |= (bitboard << 7);
        }
        if((bitboard << 9) & _not_a_border){
            mask |= (bitboard << 9);
        }
        if((bitboard << 1) & _not_a_border){
            mask |= (bitboard << 1);
        }
        if((bitboard >> 1) & _not_h_border){
            mask |= (bitboard >> 1);
        }
        if((bitboard >> 7) & _not_a_border){
            mask |= (bitboard >> 7);
        }
        if((bitboard >> 9) & _not_h_border){
            mask |= (bitboard >> 9);
        }

        mask |= (bitboard << 8);
        mask |= (bitboard >> 8);
        return mask;
        
    }

    uint64_t LegalMove::rooksMoves(int position, const Board& board, bool color){
        uint64_t mask = 0;
        int line = position/8;
        int column = position%8;

        for( int i = line + 1 ; i < 8 ; i++){//up
            if( ( 1ULL << ( i*8 + column ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( i*8 + column ) );
            if( ( 1ULL << ( i*8 + column ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        for( int i = line - 1 ; i > -1 ; i--){//down
            if( ( 1ULL << ( i*8 + column ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( i*8 + column ) );
            if( ( 1ULL << ( i*8 + column ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        for( int j = column + 1 ; j < 8 ; j++){//right
            if( ( 1ULL << ( line*8 + j ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( line*8 + j ) );
            if( ( 1ULL << ( line*8 + j ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        for( int j = column - 1 ; j > -1 ; j--){//left
            if( ( 1ULL << ( line*8 + j ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( line*8 + j ) );
            if( ( 1ULL << ( line*8 + j ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        return mask;
    }

    uint64_t LegalMove::bishopsMoves(int position, const Board& board, bool color ){
        uint64_t mask = 0;
        int line = position/8;
        int column = position%8;
        int i,j;

        for( i = line + 1 , j = column + 1 ; i < 8 && j < 8 ; i++, j++){//up right
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( i*8 + j ) );
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        for( i = line - 1 , j = column + 1 ; i > -1 && j < 8 ; i--, j++){//down right
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( i*8 + j ) );
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        for( i = line + 1 , j = column - 1 ; i < 8 && j > -1 ; i++, j--){//up left
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( i*8 + j ) );
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }
        for( i = line - 1 , j = column - 1 ; i > -1 && j > -1 ; i--, j--){//down left
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[color]->all.value ) ){
                break;
            }
            mask |= ( 1ULL << ( i*8 + j ) );
            if( ( 1ULL << ( i*8 + j ) ) & ( board._pieces[!color]->all.value ) ){
                break;
            }
        }

        return mask;
    }

    uint64_t LegalMove::queensMoves(int position, const Board& board, bool color ){
        return ( bishopsMoves(position, board, color) | rooksMoves(position, board, color) );
    }

    std::string LegalMove::bitboardToString(uint64_t mask){
        std::string res;
        res.resize(64);
        int dec = BOARD_SIZE-1;

        for(int i = 0; i<BOARD_SIZE; i++){
            if((mask >> i)&1){
                res[dec] = '1';
            }
            else{
                res[dec] = '0';
            }
            dec--;
        }
        
        return res + std::to_string(mask);
    }

    void LegalMove::printBitboard(uint64_t mask){
        std::string chars = LegalMove::bitboardToString(mask);
        for (int current_y = 0; current_y <= 7; current_y++){
                for (int current_x = 7; current_x >= 0; current_x--){
                    std::cout << chars[current_y * 8 + current_x] << ' ';
                }
                std::cout << std::endl;
            }
        std::cout<< "Valeur totale du bitboard : "<< std::endl;
        std::cout << chars.substr(64) << std::endl;
    }


    void LegalMove::initLookupTable(){
        for(int position = 0; position < 64; position ++){
            _pawns_attacks_table[white][position] = pawnsAttacks(white,position);
            _pawns_attacks_table[black][position] = pawnsAttacks(black,position);
            _pawns_moves_table[white][position] = pawnsMoves(white,position);
            _pawns_moves_table[black][position] = pawnsMoves(black,position);
            _knights_moves_table[position] = knightsMoves(position);
            _kings_moves_table[position] = kingsMoves(position);
        }
    }
    
    std::vector<Move> LegalMove::legalMove(const Board& board, bool color){
        
        std::vector<Move> moves;

        pawnsLegalMoves(board, color, moves);
        kingLegalMoves(board, color, moves);
        knightsLegalMoves(board, color, moves);
        queensLegalMoves(board, color, moves);
        bishopsLegalMoves(board, color, moves);
        rooksLegalMoves(board, color, moves);

        return moves;
    }

    void LegalMove::pawnsLegalMoves(const Board& board, bool color, std::vector<Move>& moves){
        uint64_t movable;
        uint64_t rushable;
        uint64_t possibly_eat;
        Bitboard bitboard = board._pieces[color]->pawns;

        for(int current_piece_position: getPositionsV2(bitboard.value)){
            rushable = _pawns_moves_table[color][current_piece_position] -
                       (_pawns_moves_table[color][current_piece_position]
                    & (board._pieces[!color]->all.value | board._pieces[color]->all.value));
            possibly_eat = _pawns_attacks_table[color][current_piece_position] & board._pieces[!color]->all.value;
            movable = possibly_eat | rushable;

            if (movable == 0){
                continue;
            }

            for(int pos_target: getPositionsV2(movable)){// target loop
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = pos_target;
                moves.emplace_back(move);
            }
        }
    }

    void LegalMove::kingLegalMoves(const Board& board, bool color, std::vector<Move>& moves){
        uint64_t movable;
        Bitboard bitboard = board._pieces[color]->king;

        for(int current_piece_position: getPositionsV2(bitboard.value)){
            movable = _kings_moves_table[current_piece_position]
                    - (_kings_moves_table[current_piece_position] & board._pieces[color]->all.value);

            if (movable == 0) {
                continue;
            }

            for(int pos_target:pdp_chess::getPositionsV2(movable)){// target loop
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = pos_target;
                moves.emplace_back(move);
            }
        }
    }

    void LegalMove::knightsLegalMoves(const Board& board, bool color, std::vector<Move>& moves){
        uint64_t movable;
        Bitboard bitboard = board._pieces[color]->knights;

        for (auto current_piece_position : pdp_chess::getPositionsV2(bitboard.value)){
            movable = _knights_moves_table[current_piece_position]
                    - (_knights_moves_table[current_piece_position] & board._pieces[color]->all.value);

            if (movable == 0){
                continue;
            }

            for(int target_position : pdp_chess::getPositionsV2(movable)){// target loop
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = target_position;
                moves.emplace_back(move);
            }
        }
    }

    void LegalMove::rooksLegalMoves(const Board& board, bool color, std::vector<Move>& moves){
        Bitboard bitboard = board._pieces[color]->rooks;

        for (auto current_piece_position : getPositionsV2(bitboard.value) ){
            uint64_t movable;
            movable = rooksMoves(current_piece_position, board, color);

            if (movable == 0){
                continue;
            }

            for (auto current_target_position : getPositionsV2(movable) ){
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = current_target_position;
                moves.emplace_back(move);
            }
        }
    }

    void LegalMove::bishopsLegalMoves(const Board& board, bool color, std::vector<Move>& moves){
        Bitboard bitboard = board._pieces[color]->bishops;

        for (auto current_piece_position : getPositionsV2(bitboard.value) ){
            uint64_t movable;
            movable = bishopsMoves(current_piece_position, board, color);

            if (movable == 0){
                continue;
            }

            for (auto current_target_position : getPositionsV2(movable) ){
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = current_target_position;
                moves.emplace_back(move);
            }
        }
    }

    void LegalMove::queensLegalMoves(const Board& board, bool color, std::vector<Move>& moves){
        Bitboard bitboard = board._pieces[color]->queen;

        for (auto current_piece_position : getPositionsV2(bitboard.value) ){
            uint64_t movable;
            movable = queensMoves(current_piece_position, board, color);

            if (movable == 0){
                continue;
            }

            for (auto current_target_position : getPositionsV2(movable) ){
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = current_target_position;
                moves.emplace_back(move);
            }
        }
    }
}