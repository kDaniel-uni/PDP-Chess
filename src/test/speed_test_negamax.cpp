//
// Pdp_chess university project
//

#include "director.h"

using namespace pdp_chess;

int main(int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];

    int number_of_game = 100;

    Director director = Director();
    director.setDraw(false);

    MatchParameters matchParameters = MatchParameters();
    PlayerParameters blackPlayerParameters = PlayerParameters();
    blackPlayerParameters.player_type = pdp_chess::AlphaBeta;
    AIParameters blackAIParameters = AIParameters();
    blackAIParameters.heuristic_parameters = HeuristicParameters();
    blackAIParameters.depth = 1;
    blackPlayerParameters.ai_parameters = blackAIParameters;

    PlayerParameters whitePlayerParameters = PlayerParameters();
    whitePlayerParameters.player_type = pdp_chess::NegaMax;
    AIParameters whiteAIParameters = AIParameters();

    whiteAIParameters.heuristic_parameters = HeuristicParameters();

    if (arg == "1"){
        whiteAIParameters.depth = 1;
        number_of_game = 10000;
    } else if (arg == "2") {
        whiteAIParameters.depth = 2;
        number_of_game = 10000;
    } else if (arg == "3") {
        whiteAIParameters.depth = 3;
        number_of_game = 1000;
    } else if (arg == "4") {
        whiteAIParameters.depth = 4;
        number_of_game = 100;
    } else if (arg == "5") {
        whiteAIParameters.depth = 5;
        number_of_game = 10;
    } else if (arg == "6") {
        whiteAIParameters.depth = 6;
        number_of_game = 10;
    }else {
        return EXIT_FAILURE;
    }

    whitePlayerParameters.ai_parameters = whiteAIParameters;

    matchParameters.black_player_parameters = blackPlayerParameters;
    matchParameters.white_player_parameters = whitePlayerParameters;

    director.loadMatchFromMatchParameters(matchParameters, true);

    auto t1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < number_of_game; ++i) {
        director.playMatch(false);
        director.resetGame();
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(t2 - t1);
    std::cout << number_of_game << " game played" << std::endl;
    std::cout << "Average game time " << duration.count() / number_of_game << " ns" << std::endl;
}
