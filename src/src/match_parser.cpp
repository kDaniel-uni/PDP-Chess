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

        matchParameters.whitePlayerParameters = GetPlayerParameters(whiteData);
        matchParameters.blackPlayerParameters = GetPlayerParameters(blackData);

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
            std::string existingType = GetStringFromPlayerType((PlayerType) typeIndex);

            if (playerTypeString.compare(existingType)){
                playerType = (PlayerType) typeIndex;
                break;
            }
        }

        if (playerType == PlayerNone){
            playerType = Random;
        }

        playerParameters.playerType = playerType;

        if (playerType == Human){
            return playerParameters;
        }

        AIParameters aiParameters = AIParameters();
        aiParameters.depth = playerData["Depth"].asInt();
        aiParameters.heuristicParameters = GetHeuristicParameters(playerData["Heuristic"]);

        playerParameters.aiParameters = aiParameters;
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

            heuristicParameters.ChangeValue(parameterType, currentParameters["Value"].asInt());
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
            std::string existingParameter = GetStringFromHeuristicParameterType((HeuristicParameterType) typeIndex);

            if (parameterType.compare(existingParameter)){
                return (HeuristicParameterType) typeIndex;
            }
        }

        return HeuristicNone;
    }

}
