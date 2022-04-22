//
// Pdp_chess university project
//

#include "match_parser.h"

namespace pdp_chess {

    /* Returns a MatchParameters populated with PlayerParameters for each player color
     * */
    MatchParameters GetMatchParameters(Json::Value& matchData){
        MatchParameters matchParameters = MatchParameters();

        Json::Value& whiteData = matchData["White"];
        Json::Value& blackData = matchData["Black"];

        matchParameters.white_player_parameters = GetPlayerParameters(whiteData);
        matchParameters.black_player_parameters = GetPlayerParameters(blackData);

        return matchParameters;
    }


    /* Returns a PlayerParameters which contains only its type if human
     * It also contains its depth and AIParameters if it's not human
    * */
    PlayerParameters GetPlayerParameters(Json::Value& playerData){
        PlayerParameters playerParameters = PlayerParameters();

        std::string playerTypeString = playerData["Type"].asString();
        PlayerType playerType = PlayerNone;

        for (int typeIndex = Human; typeIndex != PlayerNone; typeIndex++){
            std::string existingType = getStringFromPlayerType((PlayerType) typeIndex);

            if (playerTypeString.compare(existingType) == 0){
                playerType = (PlayerType) typeIndex;
                break;
            }
        }

        if (playerType == PlayerNone){
            playerType = Random;
        }

        playerParameters.player_type = playerType;

        if (playerType == Human){
            return playerParameters;
        }

        AIParameters aiParameters = AIParameters();
        aiParameters.depth = playerData["Depth"].asInt();
        aiParameters.heuristic_parameters = GetHeuristicParameters(playerData["Heuristic"]);

        playerParameters.ai_parameters = aiParameters;
        return playerParameters;
    }


    /* Returns an HeuristicParameters from a list of Json node
     * if there are no element in the list the HeuristicParameters struct keeps its default values
     * */
    HeuristicParameters GetHeuristicParameters(Json::Value& heuristicParametersList){
        HeuristicParameters heuristicParameters = HeuristicParameters();

        for (int i = 0; i < heuristicParametersList.size(); ++i) {
            Json::Value& currentParameters = heuristicParametersList[i];

            HeuristicParameterType parameterType = GetHeuristicParameterType(currentParameters["Type"]);
            if (parameterType == HeuristicNone){
                continue;
            }

            heuristicParameters.changeValue(parameterType, currentParameters["Value"].asInt());
        }

        return heuristicParameters;
    }


    /* Read the string associated with the heuristic parameter type from the json node
     * Returns a HeuristicParameterType if the string equals an existing parameter
     * Returns None if it doesn't find a match
     * */
    HeuristicParameterType GetHeuristicParameterType(Json::Value& heuristicParametersElement){

        std::string parameterType = heuristicParametersElement.asString();

        for (int typeIndex = Pawns; typeIndex != HeuristicNone; typeIndex++){
            std::string existingParameter = getStringFromHeuristicParameterType((HeuristicParameterType) typeIndex);

            if (parameterType.compare(existingParameter) == 0){
                return (HeuristicParameterType) typeIndex;
            }
        }

        return HeuristicNone;
    }

}
