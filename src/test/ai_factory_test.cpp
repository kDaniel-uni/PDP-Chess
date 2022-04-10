//
// Pdp_chess university project
//

#include "ai_factory.h"
#include "game.h"
#include <fstream>
#include <chrono>

using namespace pdp_chess;

int main (int argc, char *argv[]) {

    if (argc > 2) return EXIT_FAILURE;
    if (argc == 1) return EXIT_FAILURE;

    std::string arg = argv[1];

    if (arg == "1"){
        std::ifstream input_stream("../json_exemple/ai_test.json");
        Json::Reader reader;
        Json::Value json_object;
        reader.parse(input_stream, json_object);

        LegalMove legal_move = LegalMove();
        AiFactory ai_factory = AiFactory(legal_move);

        AiPlayer* white_player = &ai_factory.createAiPlayer(json_object["AI"]);
        AiPlayer* black_player = &ai_factory.createAiPlayer(json_object["AI2"]);
        Game g = Game(white_player, black_player);
        g.fromString("RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr");

        auto t1 = std::chrono::high_resolution_clock::now();

        g.start();

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(t2 - t1);
        std::cout << duration.count() << " ms" << std::endl;
    }
}