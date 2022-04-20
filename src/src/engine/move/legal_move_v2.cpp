//
// Pdp_chess university project
//

#include "legal_move_v2.h"

namespace pdp_chess {

    std::vector<Move> LegalMoveV2::GetLegalMoves(const Board &board, bool color) {

        std::vector<Move> moves;

        pawnsLegalMoves(board, color, moves);
        kingLegalMoves(board, color, moves);
        knightsLegalMoves(board, color, moves);
        queensLegalMoves(board, color, moves);
        bishopsLegalMoves(board, color, moves);
        rooksLegalMoves(board, color, moves);

        return moves;
    }

    LegalMoveV2::LegalMoveV2() {
        initLookupTable();
    }

    uint64_t LegalMoveV2::pawnsMoves(int color, int position) {
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if (color) {
            if ((position > 7) & (position < 16)) {
                mask |= (bitboard << 16);
            }
            mask |= (bitboard << 8);
        } else {
            if ((position > 47) & (position < 56)) {
                mask |= (bitboard >> 16);
            }
            mask |= (bitboard >> 8);
        }

        return mask;
    }

    uint64_t LegalMoveV2::pawnsAttacks(int color, int position) {
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if (color) {
            if ((bitboard << 7) & _not_h_border) {
                mask |= (bitboard << 7);
            }
            if ((bitboard << 9) & _not_a_border) {
                mask |= (bitboard << 9);
            }
        } else {
            if ((bitboard >> 7) & _not_a_border) {
                mask |= (bitboard >> 7);
            }
            if ((bitboard >> 9) & _not_h_border) {
                mask |= (bitboard >> 9);
            }
        }

        return mask;
    }

    uint64_t LegalMoveV2::knightsMoves(int position) {
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if ((bitboard >> 17) & _not_h_border) {
            mask |= (bitboard >> 17);
        }
        if ((bitboard >> 15) & _not_a_border) {
            mask |= (bitboard >> 15);
        }
        if ((bitboard >> 10) & _not_gh_border) {
            mask |= (bitboard >> 10);
        }
        if ((bitboard >> 6) & _not_ab_border) {
            mask |= (bitboard >> 6);
        }

        if ((bitboard << 17) & _not_a_border) {
            mask |= (bitboard << 17);
        }
        if ((bitboard << 15) & _not_h_border) {
            mask |= (bitboard << 15);
        }
        if ((bitboard << 10) & _not_ab_border) {
            mask |= (bitboard << 10);
        }
        if ((bitboard << 6) & _not_gh_border) {
            mask |= (bitboard << 6);
        }

        return mask;
    }

    uint64_t LegalMoveV2::kingsMoves(int position) {
        uint64_t b = 1;
        uint64_t bitboard = (b << position);
        uint64_t mask = 0;

        if ((bitboard << 7) & _not_h_border) {
            mask |= (bitboard << 7);
        }
        if ((bitboard << 9) & _not_a_border) {
            mask |= (bitboard << 9);
        }
        if ((bitboard << 1) & _not_a_border) {
            mask |= (bitboard << 1);
        }
        if ((bitboard >> 1) & _not_h_border) {
            mask |= (bitboard >> 1);
        }
        if ((bitboard >> 7) & _not_a_border) {
            mask |= (bitboard >> 7);
        }
        if ((bitboard >> 9) & _not_h_border) {
            mask |= (bitboard >> 9);
        }

        mask |= (bitboard << 8);
        mask |= (bitboard >> 8);
        return mask;

    }

    uint64_t LegalMoveV2::rooksMoves(int position, const Board &board, bool color) {
        uint64_t mask = 0;
        int line = position / 8;
        int column = position % 8;

        for (int i = line + 1; i < 8; i++) {//up
            if ((1ULL << (i * 8 + column)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (i * 8 + column));
            if ((1ULL << (i * 8 + column)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        for (int i = line - 1; i > -1; i--) {//down
            if ((1ULL << (i * 8 + column)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (i * 8 + column));
            if ((1ULL << (i * 8 + column)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        for (int j = column + 1; j < 8; j++) {//right
            if ((1ULL << (line * 8 + j)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (line * 8 + j));
            if ((1ULL << (line * 8 + j)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        for (int j = column - 1; j > -1; j--) {//left
            if ((1ULL << (line * 8 + j)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (line * 8 + j));
            if ((1ULL << (line * 8 + j)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        return mask;
    }

    uint64_t LegalMoveV2::bishopsMoves(int position, const Board &board, bool color) {
        uint64_t mask = 0;
        int line = position / 8;
        int column = position % 8;
        int i, j;

        for (i = line + 1, j = column + 1; i < 8 && j < 8; i++, j++) {//up right
            if ((1ULL << (i * 8 + j)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (i * 8 + j));
            if ((1ULL << (i * 8 + j)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        for (i = line - 1, j = column + 1; i > -1 && j < 8; i--, j++) {//down right
            if ((1ULL << (i * 8 + j)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (i * 8 + j));
            if ((1ULL << (i * 8 + j)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        for (i = line + 1, j = column - 1; i < 8 && j > -1; i++, j--) {//up left
            if ((1ULL << (i * 8 + j)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (i * 8 + j));
            if ((1ULL << (i * 8 + j)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }
        for (i = line - 1, j = column - 1; i > -1 && j > -1; i--, j--) {//down left
            if ((1ULL << (i * 8 + j)) & (board._pieces[color]->all.value)) {
                break;
            }
            mask |= (1ULL << (i * 8 + j));
            if ((1ULL << (i * 8 + j)) & (board._pieces[!color]->all.value)) {
                break;
            }
        }

        return mask;
    }

    uint64_t LegalMoveV2::queensMoves(int position, const Board &board, bool color) {
        return (bishopsMoves(position, board, color) | rooksMoves(position, board, color));
    }

    std::string LegalMoveV2::bitboardToString(uint64_t mask) {
        std::string res;
        res.resize(64);
        int dec = BOARD_SIZE - 1;

        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((mask >> i) & 1) {
                res[dec] = '1';
            } else {
                res[dec] = '0';
            }
            dec--;
        }

        return res + std::to_string(mask);
    }

    void LegalMoveV2::printBitboard(uint64_t mask) {
        std::string chars = bitboardToString(mask);
        for (int current_y = 0; current_y <= 7; current_y++) {
            for (int current_x = 7; current_x >= 0; current_x--) {
                std::cout << chars[current_y * 8 + current_x] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "Valeur totale du bitboard : " << std::endl;
        std::cout << chars.substr(64) << std::endl;
    }


    void LegalMoveV2::initLookupTable() {
        for (int position = 0; position < 64; position++) {
            _pawns_attacks_table[white][position] = pawnsAttacks(white, position);
            _pawns_attacks_table[black][position] = pawnsAttacks(black, position);
            _pawns_moves_table[white][position] = pawnsMoves(white, position);
            _pawns_moves_table[black][position] = pawnsMoves(black, position);
            _knights_moves_table[position] = knightsMoves(position);
            _kings_moves_table[position] = kingsMoves(position);
        }
    }

    void LegalMoveV2::pawnsLegalMoves(const Board &board, bool color, std::vector<Move> &moves) {
        uint64_t movable;
        uint64_t eatable;
        uint64_t legal_positions;
        Bitboard bitboard = board._pieces[color]->pawns;

        for (int current_piece_position: getPositionsV2(bitboard.value)) {
            uint64_t move_target_positions = _pawns_moves_table[color][current_piece_position];
            uint64_t blocked_positions = move_target_positions & (board._pieces[!color]->all.value | board._pieces[color]->all.value);

            movable = move_target_positions - blocked_positions;
            eatable = _pawns_attacks_table[color][current_piece_position] & board._pieces[!color]->all.value;

            legal_positions = eatable | movable;

            if (legal_positions == 0) {
                continue;
            }

            generateMoves(bitboard, current_piece_position, moves, legal_positions);
        }
    }

    void LegalMoveV2::kingLegalMoves(const Board &board, bool color, std::vector<Move> &moves) {
        uint64_t movable;
        Bitboard bitboard = board._pieces[color]->king;

        for (auto current_piece_position : pdp_chess::getPositionsV2(bitboard.value)){
            uint64_t target_positions = _kings_moves_table[current_piece_position];
            uint64_t blocked_by_ally = target_positions & board._pieces[color]->all.value;
            movable = target_positions - blocked_by_ally;

            if (movable == 0) {
                return;
            }

            generateMoves(bitboard, current_piece_position, moves, movable);
        }
    }

    void LegalMoveV2::knightsLegalMoves(const Board &board, bool color, std::vector<Move> &moves) {
        uint64_t movable;
        Bitboard bitboard = board._pieces[color]->knights;

        for (auto current_piece_position : pdp_chess::getPositionsV2(bitboard.value)) {
            uint64_t target_positions = _knights_moves_table[current_piece_position];
            uint64_t blocked_by_ally = target_positions & board._pieces[color]->all.value;
            movable = target_positions - blocked_by_ally;

            if (movable == 0) {
                continue;
            }

            generateMoves(bitboard, current_piece_position, moves, movable);
        }
    }

    void LegalMoveV2::rooksLegalMoves(const Board &board, bool color, std::vector<Move> &moves) {
        Bitboard bitboard = board._pieces[color]->rooks;

        for (auto current_piece_position : getPositionsV2(bitboard.value)) {
            uint64_t movable;
            movable = rooksMoves(current_piece_position, board, color);

            if (movable == 0) {
                continue;
            }

            generateMoves(bitboard, current_piece_position, moves, movable);
        }
    }

    void LegalMoveV2::bishopsLegalMoves(const Board &board, bool color, std::vector<Move> &moves) {
        Bitboard bitboard = board._pieces[color]->bishops;

        for (auto current_piece_position : getPositionsV2(bitboard.value)) {
            uint64_t movable;
            movable = bishopsMoves(current_piece_position, board, color);

            if (movable == 0) {
                continue;
            }

            generateMoves(bitboard, current_piece_position, moves, movable);
        }
    }

    void LegalMoveV2::queensLegalMoves(const Board &board, bool color, std::vector<Move> &moves) {
        Bitboard bitboard = board._pieces[color]->queen;

        for (auto current_piece_position : getPositionsV2(bitboard.value)) {
            uint64_t movable;
            movable = queensMoves(current_piece_position, board, color);

            if (movable == 0) {
                continue;
            }

            generateMoves(bitboard, current_piece_position, moves, movable);
        }
    }

    void LegalMoveV2::generateMoves(const Bitboard &source_bitboard, uint8_t source_piece_position
                                  , std::vector<Move> &moves, uint64_t movable) {
        for (auto current_target_position : getPositionsV2(movable)) {
            Move move;
            move.start_position = source_piece_position;
            move.start_type = source_bitboard.type;
            move.target_position = current_target_position;
            moves.emplace_back(move);
        }
    }
}