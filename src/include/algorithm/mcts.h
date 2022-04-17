//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MCTS_H
#define PDP_CHESS_MCTS_H

#include "ai_player.h"

namespace pdp_chess{

    class MCTS : public AIPlayer{

        public:/*
        typedef struct value{
            Board _board;
            int _nb_victory;
        }value_t;

        Move findNextMove(Board& board, color current_color){

        }

        std::string getParameters(){

        }
        typedef struct node{
            value_t _value;
            Move _move;
            struct node * _parent;
            std::vector<struct node *> _childrens;
        }node_t;

        node_t _tree;
        int _nb_experiment;

        Mcts(Heuristic& h, LegalMove& l, int depth, int nb_epx);

        node_t makeNode(Board& board, Move move, node_t * parent);
        node_t initialization(Board& board);

        node_t selection(node_t tree, int depth);
        node_t expansion(node_t tree);
        node_t simulation(node_t tree);
        void backPropagation(node_t tree, color my_color);

        node_t launch(Board& board, int nb_exp, color my_color);*/
        Move findNextMove(Board& board, color current_color);
        std::string getParameters();

    };

}

#endif //PDP_CHESS_MCTS_H
