//
// Pdp_chess university project
//

#include "orchestration/director.h"

namespace pdp_chess {

    Director::Director() {
        _game = new Game();
        _legal_move_v1 = new LegalMoveV1();
        _legal_move_v2 = new LegalMoveV2();
        _player_factory_v1 = new PlayerFactory(*_legal_move_v1);
        _player_factory_v2 = new PlayerFactory(*_legal_move_v2);
    }

    bool Director::loadMatchFromJson(std::string file_path, bool load_v1) {
        std::ifstream input_stream(file_path);
        Json::Reader reader;
        Json::Value json_object;
        bool read_success = reader.parse(input_stream, json_object);

        if (!read_success) {
            return false;
        }

        loadMatchFromMatchParameters(getMatchParameters(json_object), load_v1);

        return true;
    }

    void Director::loadMatchFromMatchParameters(MatchParameters match_parameters, bool load_v1) {

        _match_parameters = match_parameters;

        Player *white_player;
        Player *black_player;

        if (load_v1) {
            white_player = _player_factory_v1->createPlayer(_match_parameters.white_player_parameters);
            black_player = _player_factory_v1->createPlayer(_match_parameters.black_player_parameters);
        } else {
            white_player = _player_factory_v2->createPlayer(_match_parameters.white_player_parameters);
            black_player = _player_factory_v2->createPlayer(_match_parameters.black_player_parameters);
        }

        _game->setPlayer(white, white_player);
        _game->setPlayer(black, black_player);
        _game->loadBasicBoard();
    }

    void Director::loadBoard(const std::string &board) {
        _game->fromString(board);
    }

    void Director::playMatch(bool is_timed) {
        std::chrono::time_point<std::chrono::system_clock> game_start_time;
        std::chrono::time_point<std::chrono::system_clock> game_end_time;

        if (is_timed) {
            game_start_time = std::chrono::high_resolution_clock::now();
        }

        _game->start();

        if (is_timed) {
            game_end_time = std::chrono::high_resolution_clock::now();
            _game_time = duration_cast<std::chrono::milliseconds>(game_end_time - game_start_time);
            std::cout << "Game time " << _game_time.count() << " ms" << std::endl;
        }
    }

    void Director::resetGame() {
        _game->reset();
    }

    void Director::setDraw(bool draw) {
        _game->setDraw(draw);
    }
}

