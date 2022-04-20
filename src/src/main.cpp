//
// Pdp_chess university project
//

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "director.h"

using namespace pdp_chess;

bool PrintUsage(){
    std::cout << "Usage : ./pdp_chess <path_to_json> <1|2>" << std::endl;
    std::cin;
    return EXIT_FAILURE;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        return PrintUsage();
    }

    std::string arg = std::string(argv[1]);

    if (strlen(argv[2]) != 1){
        return PrintUsage();
    }

    int x = (int)argv[2][0] - 48;

    if (!(x == 1 || x == 2)){
        return PrintUsage();
    }

    Director director = Director();

    if (!director.LoadMatchFromJson(arg, x)){
        return PrintUsage();
    }

    director.PlayMatch(true);

    std::cin;
    return EXIT_SUCCESS;
}
