//
// Pdp_chess university project
//

#ifndef PDP_CHESS_JSON_PARSER_H
#define PDP_CHESS_JSON_PARSER_H

#include "parameters.h"
#include "json/json.h"

namespace pdp_chess{

    MatchParameters GetMatchParameters(Json::Value& matchData);

    PlayerParameters GetPlayerParameters(Json::Value& playerData);

    HeuristicParameters GetHeuristicParameters(Json::Value& heuristicParametersList);

    HeuristicParameterType GetHeuristicParameterType(Json::Value& heuristicParametersElement);

}

#endif //PDP_CHESS_JSON_PARSER_H
