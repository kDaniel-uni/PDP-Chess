
#include "legal_move_v2.h"
#include "bitboard_operations.h"
#include <math.h>

namespace pdp_chess {

    Legalmove::Legalmove(){
        initLookupTable();
    }

    uint64_t Legalmove::pawnsMove(int color, int position){
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

    uint64_t Legalmove::pawnsAttacks(int color, int position){
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

    uint64_t Legalmove::knightsMove(int position){
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
    uint64_t Legalmove::kingsMoves(int position){
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

    uint64_t Legalmove::rooksMove(int position, const Board& board, bool color){
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

    uint64_t Legalmove::bishopsMove(int position, const Board& board, bool color ){
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

    uint64_t Legalmove::queensMove(int position, const Board& board, bool color ){
        return ( bishopsMove(position, board, color) | rooksMove(position, board, color) );
    }

    std::string Legalmove::bitboardToString(uint64_t mask){
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

    void Legalmove::printBitboard(uint64_t mask){
        std::string chars = Legalmove::bitboardToString(mask);
        for (int current_y = 0; current_y <= 7; current_y++){
                for (int current_x = 7; current_x >= 0; current_x--){
                    std::cout << chars[current_y * 8 + current_x] << ' ';
                }
                std::cout << std::endl;
            }
        std::cout<< "Valeur totale du bitboard : "<< std::endl;
        std::cout << chars.substr(64) << std::endl;
    }


    void Legalmove::initLookupTable(){
        for(int position = 0; position < 64; position ++){
            _pawns_attack_table[white][position] = pawnsAttacks(white,position);
            _pawns_attack_table[black][position] = pawnsAttacks(black,position);
            _pawns_move_table[white][position] = pawnsMove(white,position);
            _pawns_move_table[black][position] = pawnsMove(black,position);
            _knights_move[position] = knightsMove(position);
            _kings_moves_table[position] = kingsMoves(position);
        }
    }


    
    std::vector<Move> Legalmove::legalMove(const Board& board, bool color){
        // init lookup table attacks
        
        std::vector<Move> moves;

        std::vector<Move> buffer = pawnsLegalMove(board, color);
        moves.insert(moves.end(), buffer.begin(), buffer.end());
        buffer = kingLegalMove(board,color);
        moves.insert(moves.end(), buffer.begin(), buffer.end());
        buffer = rooksLegalMove(board, color);
        moves.insert(moves.end(), buffer.begin(), buffer.end());
        buffer = bishopsLegalMove(board, color);
        moves.insert(moves.end(), buffer.begin(), buffer.end());
        buffer = queensLegalMove(board, color);
        moves.insert(moves.end(), buffer.begin(), buffer.end());
        return moves;
    }

    std::vector<Move> Legalmove::pawnsLegalMove(const Board& board, bool white){
       std::vector<Move> res;
        uint64_t result;
        uint64_t rushable;
        uint64_t possibly_eat;
        Move mv;
        mv.start_type = board._pieces[white]->pawns.type;
        for(int pos: getPositionsV2(board._pieces[white]->pawns.value)){
            mv.start_position = pos;
            rushable = _pawns_move_table[white][pos] - (_pawns_move_table[white][pos] & (board._pieces[!white]->all.value | board._pieces[white]->all.value));
            possibly_eat = _pawns_attack_table[white][pos] & board._pieces[!white]->all.value;
            result = possibly_eat | rushable;
            for(int pos_target: getPositionsV2(result)){// target loop
                mv.target_position = pos_target;
                res.emplace_back(mv);
            }
        }
        return res;
    }
    std::vector<Move> Legalmove::kingLegalMove(const Board& board, bool white){
       std::vector<Move> res;
        uint64_t result;
        uint64_t rushable;
        uint64_t possibly_eat;
        Move mv;
        mv.start_type = board._pieces[white]->king.type;
        for(int pos: getPositionsV2(board._pieces[white]->king.value)){
            mv.start_position = pos;
            rushable = _kings_moves_table[pos] - (_kings_moves_table[pos] & board._pieces[white]->all.value);
            result = possibly_eat | rushable;
            for(int pos_target:pdp_chess::getPositionsV2(result)){// target loop
                mv.target_position = pos_target;
                res.emplace_back(mv);
            }
        }
        return res;
    }

        std::vector<Move> Legalmove::rooksLegalMove(const Board& board, bool color){
        std::vector<Move> moves;
        Bitboard bitboard = board._pieces[color]->rooks;

        for (auto current_piece_position : getPositionsV2(bitboard.value) ){
            uint64_t targetable;
            targetable = rooksMove(current_piece_position, board, color);
            for (auto current_target_position : getPositionsV2(targetable) ){
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = current_target_position;
                moves.emplace_back(move);
            }
        }
        return moves;
    }

    std::vector<Move> Legalmove::bishopsLegalMove(const Board& board, bool color){
        std::vector<Move> moves;
        Bitboard bitboard = board._pieces[color]->bishops;

        for (auto current_piece_position : getPositionsV2(bitboard.value) ){
            uint64_t targetable;
            targetable = bishopsMove(current_piece_position, board, color);
            for (auto current_target_position : getPositionsV2(targetable) ){
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = current_target_position;
                moves.emplace_back(move);
            }
        }
        return moves;
    }

    std::vector<Move> Legalmove::queensLegalMove(const Board& board, bool color){
        std::vector<Move> moves;
        Bitboard bitboard = board._pieces[color]->queen;

        for (auto current_piece_position : getPositionsV2(bitboard.value) ){
            uint64_t targetable;
            targetable = queensMove(current_piece_position, board, color);
            for (auto current_target_position : getPositionsV2(targetable) ){
                Move move;
                move.start_position = current_piece_position;
                move.start_type = bitboard.type;
                move.target_position = current_target_position;
                moves.emplace_back(move);
            }
        }
        return moves;
    }

}