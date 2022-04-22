//
// Pdp_chess university project
//

#include "match_parser.h"

namespace pdp_chess {

    /* Returns a MatchParameters populated with PlayerParameters for each player color
     * */
    MatchParameters getMatchParameters(Json::Value& match_data){
        MatchParameters match_parameters = MatchParameters();

        Json::Value& white_data = match_data["White"];
        Json::Value& black_data = match_data["Black"];

        match_parameters.white_player_parameters = getPlayerParameters(white_data);
        match_parameters.black_player_parameters = getPlayerParameters(black_data);

        return match_parameters;
    }


    /* Returns a PlayerParameters which contains only its type if human
     * It also contains its depth and AIParameters if it's not human
    * */
    PlayerParameters getPlayerParameters(Json::Value& player_data){
        PlayerParameters player_parameters = PlayerParameters();

        std::string player_type_string = player_data["Type"].asString();
        PlayerType player_type = PlayerNone;

        for (int type_index = Human; type_index != PlayerNone; type_index++){
            std::string existing_type = getStringFromPlayerType((PlayerType) type_index);

            if (player_type_string.compare(existing_type) == 0){
                player_type = (PlayerType) type_index;
                break;
            }
        }

        if (player_type == PlayerNone){
            player_type = Random;
        }

        player_parameters.player_type = player_type;

        if (player_type == Human){
            return player_parameters;
        }

        AIParameters ai_parameters = AIParameters();
        ai_parameters.depth = player_data["Depth"].asInt();
        ai_parameters.heuristic_parameters = getHeuristicParameters(player_data["Heuristic"]);

        player_parameters.ai_parameters = ai_parameters;
        return player_parameters;
    }


    /* Returns an HeuristicParameters from a list of Json node
     * if there are no element in the list the HeuristicParameters struct keeps its default values
     * */
    HeuristicParameters getHeuristicParameters(Json::Value& heuristic_parameters_list){
        HeuristicParameters heuristic_parameters = HeuristicParameters();

        for (int i = 0; i < heuristic_parameters_list.size(); ++i) {
            Json::Value& current_parameters = heuristic_parameters_list[i];

            HeuristicParameterType parameter_type = getHeuristicParameterType(current_parameters["Type"]);
            if (parameter_type == HeuristicNone){
                continue;
            }

            heuristic_parameters.changeValue(parameter_type, current_parameters["Value"].asInt());
        }

        return heuristic_parameters;
    }


    /* Read the string associated with the heuristic parameter type from the json node
     * Returns a HeuristicParameterType if the string equals an existing parameter
     * Returns None if it doesn't find a match
     * */
    HeuristicParameterType getHeuristicParameterType(Json::Value& heuristic_parameters_element){

        std::string parameter_type = heuristic_parameters_element.asString();

        for (int type_index = Pawns; type_index != HeuristicNone; type_index++){
            std::string existing_parameter = getStringFromHeuristicParameterType((HeuristicParameterType) type_index);

            if (parameter_type.compare(existing_parameter) == 0){
                return (HeuristicParameterType) type_index;
            }
        }

        return HeuristicNone;
    }

}
