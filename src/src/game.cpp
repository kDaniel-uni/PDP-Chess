//
// Pdp_chess university project
//

#include "game.h"
#include <random>
#include <ctime>

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


    /* Start the game loop
     * using srand here to keep the same seed for a game*/
    void Game::start() {
        std::srand ( unsigned ( std::time(0) ) );
        while (!board.isGameOver()) {
            step();
        }

        std::cout << board.result() << " in " << board._history.size() << " moves" << std::endl;
    }


    /* Asks the current player its choice of move
     * Apply the move to the board
     * Change the color of the current player */
    void Game::step() {
        Move player_move = _players[_current_color]->askNextMove(board, _current_color);
        board.doMove(player_move);
        draw();
        _current_color = (color) !_current_color;
    }


    /* For test purpose
     * used to test engine function for which no player action is required */
    void Game::playMove(Move move) {
        board.doMove(move);
        _current_color = (color) !_current_color;
    }

    /* Draw the current game state on console
     * */
    void Game::draw() {
        std::cout << "Player : " << (_current_color ? "White" : "Black") << std::endl;
        board.draw();
    }

    /* Initialize a basic board state
     * */
    void Game::loadBasicBoard() {
        board.resetToClassic();
    }
}