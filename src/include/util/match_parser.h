//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MATCH_PARSER_H
#define PDP_CHESS_MATCH_PARSER_H

#include "orchestration/parameters.h"
#include "json/json.h"

namespace pdp_chess {

    MatchParameters getMatchParameters(Json::Value &match_data);

    PlayerParameters getPlayerParameters(Json::Value &player_data);

    HeuristicParameters getHeuristicParameters(Json::Value &heuristic_parameters_list);

    HeuristicParameterType getHeuristicParameterType(Json::Value &heuristic_parameters_element);

}

#endif //PDP_CHESS_MATCH_PARSER_H
