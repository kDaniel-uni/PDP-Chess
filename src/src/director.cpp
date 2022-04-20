//
// Pdp_chess university project
//

#include "director.h"

namespace pdp_chess {

    Director::Director() {
        _game = new Game();
        _legalMoveV1 = new LegalMoveV1();
        _legalMoveV2 = new LegalMoveV2();
        _playerFactoryV1 = new PlayerFactory(*_legalMoveV1);
        _playerFactoryV2 = new PlayerFactory(*_legalMoveV2);
    }

    bool Director::LoadMatchFromJson(std::string file_path, bool load_v1) {
        std::ifstream input_stream(file_path);
        Json::Reader reader;
        Json::Value json_object;
        bool read_success = reader.parse(input_stream, json_object);

        if (!read_success){
            return false;
        }

        _matchParameters = GetMatchParameters(json_object);

        Player* white_player;
        Player* black_player;

        if (load_v1){
            white_player = _playerFactoryV1->createPlayer(_matchParameters.whitePlayerParameters);
            black_player = _playerFactoryV1->createPlayer(_matchParameters.blackPlayerParameters);
        } else {
            white_player = _playerFactoryV2->createPlayer(_matchParameters.whitePlayerParameters);
            black_player = _playerFactoryV2->createPlayer(_matchParameters.blackPlayerParameters);
        }

        _game->setPlayer(white, white_player);
        _game->setPlayer(black, black_player);
        _game->loadBasicBoard();

        return true;
    }

    void Director::LoadBoard(const std::string &board) {
        _game->fromString(board);
    }

    void Director::PlayMatch(bool is_timed) {
        std::chrono::time_point<std::chrono::system_clock> _gameStartTime;
        std::chrono::time_point<std::chrono::system_clock> _gameEndTime;

        if (is_timed){
             _gameStartTime = std::chrono::high_resolution_clock::now();
        }

        _game->start();

        if (is_timed){
            _gameEndTime = std::chrono::high_resolution_clock::now();
            _gameTime = duration_cast<std::chrono::milliseconds>(_gameEndTime - _gameStartTime);
            std::cout << "Game time " << _gameTime.count() << " ms" << std::endl;
        }
    }

    void Director::ResetGame(){
        _game->reset();
    }
}

