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

    MatchParameters matchParameters = MatchParameters();
    PlayerParameters blackPlayerParameters = PlayerParameters();
    blackPlayerParameters.playerType = pdp_chess::Random;

    PlayerParameters whitePlayerParameters = PlayerParameters();
    whitePlayerParameters.playerType = pdp_chess::AlphaBeta;
    AIParameters whiteAIParameters = AIParameters();

    whiteAIParameters.heuristicParameters = HeuristicParameters();

    if (arg == "1"){
        whiteAIParameters.depth = 1;
    } else if (arg == "2") {
        whiteAIParameters.depth = 2;
    } else if (arg == "3") {
        whiteAIParameters.depth = 3;
    } else if (arg == "4") {
        whiteAIParameters.depth = 4;
    } else {
        return EXIT_FAILURE;
    }

    whitePlayerParameters.aiParameters = whiteAIParameters;

    matchParameters.blackPlayerParameters = blackPlayerParameters;
    matchParameters.whitePlayerParameters = whitePlayerParameters;

    director.LoadMatchFromMatchParameters(matchParameters, true);

    auto t1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < number_of_game; ++i) {
        director.PlayMatch(false);
        director.ResetGame();
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << number_of_game << " game played" << std::endl;
    std::cout << "Average game time " << duration.count() / number_of_game << " ms" << std::endl;
}

