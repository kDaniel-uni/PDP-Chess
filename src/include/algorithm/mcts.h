//
// Pdp_chess university project
//

#ifndef PDP_CHESS_MCTS_H
#define PDP_CHESS_MCTS_H

#include "board.h"
#include "move.h"
#include "player/ai_player.h"
#include "legal_move.h"
#include "heuristic.h"

namespace pdp_chess{

    class Mcts : public AiPlayer{

        public:
            struct node;

            typedef struct node{
                Board _board;
                int _nb_victory;
                int _nb_exp;
                color _color;
                Move * _move;
                struct node * _parent;
                std::vector<struct node> _childrens;
            }node_t;

            node_t _tree;
            int _nb_experiment;

            Mcts(Heuristic& h, LegalMove& l, int depth, int nb_epx);

            node_t makeNode(Board& board, Move * move, node_t * parent, color c);
            node_t initialization(Board& board, color current_color);

            node_t selection(node_t tree, int depth);
            node_t expansion(node_t tree);
            node_t simulation(node_t tree);
            void backPropagation(node_t * tree);

            node_t launch(Board& board, int nb_exp, color my_color);
            Move askNextMove(Board& board, color current_color);
            std::string getParameters();

    };
}

#endif //PDP_CHESS_MCTS_H