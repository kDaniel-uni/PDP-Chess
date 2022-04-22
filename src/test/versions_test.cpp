//
// Pdp_chess university project
//

#include <chrono>
#include "orchestration/director.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];

    if (arg == "1"){
        int number_of_game = 10;

        Director director = Director();
        director.loadMatchFromJson("../json_exemple/template.json", true);

        auto t1 = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < number_of_game; ++i) {
            director.playMatch(false);
            director.resetGame();
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << number_of_game << " game played" << std::endl;
        std::cout << "Average game time " << duration.count()/number_of_game << " ms" << std::endl;
    } if (arg == "2"){
        int number_of_game = 10;

        Director director = Director();
        director.loadMatchFromJson("../json_exemple/template.json", false);

        auto t1 = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < number_of_game; ++i) {
            director.playMatch(false);
            director.resetGame();
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << number_of_game << " game played" << std::endl;
        std::cout << "Average game time " << duration.count()/number_of_game << " ms" << std::endl;
    }
}