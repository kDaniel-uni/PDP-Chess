//
// Pdp_chess university project
//

#include "ai_factory.h"
#include "game.h"
#include <fstream>
#include <chrono>
#include "legal_move_v1.h"
#include "legal_move_v2.h"

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];

    if (arg == "1"){
        int number_of_game = 200;

        std::ifstream input_stream("../json_exemple/ai_test.json");
        Json::Reader reader;
        Json::Value json_object;
        reader.parse(input_stream, json_object);

        LegalMoveV1 legal_move = LegalMoveV1();
        AiFactory ai_factory = AiFactory(legal_move);

        AiPlayer* white_player = &ai_factory.createAiPlayer(json_object["White"]);
        AiPlayer* black_player = &ai_factory.createAiPlayer(json_object["Black"]);
        Game g = Game(white_player, black_player);


        auto t1 = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < number_of_game; ++i) {
            g.reset();
            g.start();
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << number_of_game << " game played" << std::endl;
        std::cout << "Average game time " << duration.count()/number_of_game << " ms" << std::endl;
    }
}