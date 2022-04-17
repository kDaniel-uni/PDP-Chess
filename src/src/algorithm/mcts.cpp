//
// Pdp_chess university project
//

#include "mcts.h"

namespace pdp_chess {
        Mcts::Mcts(Heuristic &h, LegalMove &l, int d, int nb_exp){
           _heuristic = &h;
           _legal_move = &l;
           _depth = d;
           _nb_experiment = nb_exp;
        }
    class Mcts : public AiPlayer{/*

        node_t Mcts::makeNode(Board& board, Move move, node_t * parent){
            value_t val;
            val._board = board;
            val._nb_experiment = 0;
            val._nb_victory = 0;

            tree.value = val;
            tree._move = move;
            tree._parent = parent;
            tree._childrens = new vector<Move>();
        }

        node_t Mcts::initialization(Board& board){
            node_t tree = makeNode(board, NULL);
        }

        node_t Mcts::selection(node_t tree, int depth){
            Board board = tree._value._board;
            if(depth > 0 || board.isGameOver())
                return tree;          
            else{
                std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
                std::shuffle(legal_moves.begin(), legal_moves.end(), g);
                board = board.doMove(legal_moves[0]);
                node_t children = makeNode(board, legal_moves[0], tree);
                tree._childrens.push_back(&children);
                selection(children, depth-1);
            }
        }

        node_t Mcts::expansion(node_t tree){
            Board board = tree._value._board;
            if(board.isGameOver())
                return tree;          
            else{
                std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
                std::shuffle(legal_moves.begin(), legal_moves.end(), g);
                board = board.doMove(legal_moves[0]);
                node_t children = makeNode(board, legal_moves[0], tree);
                tree._childrens.push_back(&children);
                return children;
            }
        }

        node_t Mcts::simulation(node_t tree){
            while(!tree._value._board.isGameOver()){
                Board board = tree._value._board;
                std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
                std::shuffle(legal_moves.begin(), legal_moves.end(), g);
                board = board.doMove(legal_moves[0]);
                node_t children = makeNode(board, legal_moves[0], tree);
                tree._childrens.push_back(&children);
                tree = children;
            }
            return tree;
        }

        void Mcts::backPropagation(node_t tree, color my_color){
            bool victory = tree._value._board._pieces[my_color]->king.value != 0;
            while(tree != NULL){
                if(victory)
                    tree._value._nb_victory++;
                tree._value._nb_experiment++;
                tree = tree._parent;
            }
        }

        node_t Mcts::launch(Board& board, int nb_exp, color my_color){
            node_t tree = initialization(board);
            for(int i=0; i<nb_exp; i++){
                node_t select_node = selection(tree, _depth);
                node_t deep_node = expansion(select_node);
                node_t leaf = simulation(deep_node);
                backPropagation(leaf, my_color);
            }
            return tree;
        }
*/
        Move Mcts::findNextMove(Board& board, color current_color){/*
            node_t tree = launch(board, nb_exp, current_color);
            int nb_vitory = 0;
            node_t best_node;
            for(int i=0; i<tree._childrens.size(); i++){
                if(tree._childrens[i]._value._nb_victory >= nb_vitory){
                    best_node = tree._childrens[i];
                    nb_vitory = best_node._value._nb_victory;
                }
            }
            return best_node._move;*/
        }

        std::string getParameters(){

        }
    };

}