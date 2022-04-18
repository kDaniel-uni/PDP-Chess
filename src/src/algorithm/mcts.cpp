//
// Pdp_chess university project
//

#include "mcts.h"

namespace pdp_chess {
        struct node;

        typedef struct node{
                Board _board;
                int _nb_victory;
                int _nb_exp;
                Move * _move;
                struct node * _parent;
                std::vector<struct node> _childrens;
        }node_t;

        Mcts::Mcts(Heuristic &h, LegalMove &l, int d, int nb_exp){
           _heuristic = &h;
           _legal_move = &l;
           _depth = d;
           _nb_experiment = nb_exp;
        }
    class Mcts : public AiPlayer{/*

        Mcts::node_t Mcts::makeNode(Board& board, Move * move, node_t * parent){
            node_t tree;
            tree._board = board;
            tree._nb_exp = 0;
            tree._nb_victory = 0;
            tree._move = move;
            tree._parent = parent;
            return tree;
        }

        Mcts::node_t Mcts::initialization(Board& board){
            node_t tree = makeNode(board, NULL, NULL);
            return tree;
        }

        Mcts::node_t Mcts::selection(node_t tree, int depth, color current_color){
            Board board = tree._board;
            if(depth <= 0 || board.isGameOver()){
                return tree;          
            }
            else{
                std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
                //randomiser le legal move
                Move move = legal_moves[0];
                board.doMove(move);
                node_t children = makeNode(board, &move, &tree);
                tree._childrens.push_back(children);
                if(current_color == white)
                    selection(children, depth-1, black);
                else
                    selection(children, depth-1, white);
            }
        }

        Mcts::node_t Mcts::expansion(node_t tree, color current_color){
            printf("0\n");
            Board board = tree._board;
            if(board.isGameOver())
                return tree;          
            else{
                std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
                //randomiser le legal move
                Move move = legal_moves[0];
                board.doMove(move);
                node_t children = makeNode(board, &move, &tree);
                tree._childrens.push_back(children);
                return children;
            }
        }

        Mcts::node_t Mcts::simulation(node_t tree, color current_color){
            while(!tree._board.isGameOver()){
                Board board = tree._board;
                std::vector<Move> legal_moves = _legal_move->legalMove(board, current_color);
                //randomiser le legal move
                Move move = legal_moves[0];
                board.doMove(move);
                node_t children = makeNode(board, &move, &tree);
                tree._childrens.push_back(children);
                tree = children;
            }
            return tree;
        }

        void Mcts::backPropagation(node_t * tree, color my_color){
            bool victory = tree->_board._pieces[my_color]->king.value != 0;
            while(&tree != NULL){
                if(victory)
                    tree->_nb_victory++;
                tree->_nb_exp++;
                tree = tree->_parent;
            }
        }

        Mcts::node_t Mcts::launch(Board& board, int nb_exp, color my_color){
            node_t tree = initialization(board);
            for(int i=0; i<nb_exp; i++){
                node_t select_node = selection(tree, _depth, my_color);
                printf("1\n");
                node_t deep_node = expansion(select_node, my_color);
                node_t leaf = simulation(deep_node, my_color);
                backPropagation(&leaf, my_color);
            }
            return tree;
        }

        Move Mcts::askNextMove(Board& board, color current_color){
            node_t tree = launch(board, _nb_experiment, current_color);
            int nb_vitory = 0;
            node_t best_node;
            for(int i=0; i<tree._childrens.size(); i++){
                if(tree._childrens[i]._nb_victory >= nb_vitory){
                    best_node = tree._childrens[i];
                    nb_vitory = best_node._nb_victory;
                }
            }
            return *(best_node._move);
        }

        std::string getParameters(){
            return "";
        }

}