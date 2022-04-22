//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MCTS_H
#define PDP_CHESS_MCTS_H

#include "ai_player.h"

namespace pdp_chess {

    class MCTS : public AIPlayer {

    public:
        struct node;

        typedef struct node {
            Board _board;
            int _nb_victory;
            int _nb_exp;
            Move *_move;
            struct node *_parent;
            std::vector<struct node> _childrens;
        } node_t;

        MCTS(Heuristic &heuristic, LegalMove &legalMove, int depth, int nb_epx);

        Move askNextMove(Board &board, color current_color) override;

        std::string getParameters();

        node_t _tree;
        int _nb_experiment;

        node_t makeNode(Board &board, Move *move, node_t *parent);

        node_t initialization(Board &board);

        node_t selection(node_t tree, int depth, color current_color);

        node_t expansion(node_t tree, color current_color);

        node_t simulation(node_t tree, color current_color);

        void backPropagation(node_t *tree, color my_color);

        node_t launch(Board &board, int nb_exp, color my_color);

    };

}

#endif //PDP_CHESS_MCTS_H
