//
// Pdp_chess university project
//

#include "game.h"

namespace pdp_chess {

    /* Special constructor, used to test engine function for which no player action is required */
    Game::Game() : _players{nullptr, nullptr} {
        board = Board();
        _current_color = white;
    }


    /* Full construction, initialize the board and assign the players and their colors */
    Game::Game(Player *white_player, Player *black_player) : _players{black_player, white_player} {
        board = Board();
        _current_color = white;
    }


    /* Loading a board state from a string */
    void Game::fromString(const std::string &string) {
        board.fromString(string.c_str());
    }


    /* Start the game loop */
    void Game::start() {
        while (!board.isGameOver()) {
            step();
        }
    }


    /* Asks the current player its choice of move
     * Apply the move to the board
     * Change the color of the current player */
    void Game::step() {
        Move player_move = _players[_current_color]->askNextMove(board, _current_color);
        board.doMove(player_move);
        _current_color = (color) !_current_color;
    }


    /* For test purpose
     * used to test engine function for which no player action is required */
    void Game::playMove(Move move) {
        board.doMove(move);
        _current_color = (color) !_current_color;
    }
}