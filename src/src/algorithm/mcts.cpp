#include "board.h"
#include "move.h"
#include "player/ai_player.h"
#include "legal_move.h"
#include "heuristic.h"
#include "mcts.h"

namespace pdp_chess {
        struct node;

        typedef struct node{
                Board _board;
                int _nb_victory;
                int _nb_exp;
                Move * _move;
                color _color;
                struct node * _parent;
                std::vector<struct node> _childrens;
        }node_t;

        Mcts::Mcts(Heuristic &h, LegalMove &l, int d, int nb_exp){
           _heuristic = &h;
           _legal_move = &l;
           _depth = d;
           _nb_experiment = nb_exp;
        }

        Mcts::node_t Mcts::makeNode(Board& board, Move * move, node_t * parent, color c){
            node_t tree;
            tree._board = board;
            tree._nb_exp = 0;
            tree._nb_victory = 0;
            tree._move = move;
            tree._parent = parent;
            tree._color = c;
            return tree;
        }

        Mcts::node_t Mcts::initialization(Board& board, color current_color){
            node_t tree = makeNode(board, NULL, NULL, current_color);
            return tree;
        }

        Mcts::node_t Mcts::selection(node_t tree, int depth){
            if(depth <= 0 || tree._board.isGameOver()){
                return tree;          
            }
            else{
                Board board = tree._board;
                std::vector<Move> legal_moves = _legal_move->legalMove(board, tree._color);
                //randomiser le legal move
                Move move = legal_moves[0];
                node_t children;
                board.doMove(move);
                std::string string_board = board.toString();
                bool in_tree = false;
                for(int i=0; i<tree._childrens.size(); i++){
                    std::string board_tree = tree._childrens[i]._board.toString();
                    if(string_board.compare(board_tree) == 0){
                        children = tree._childrens[i];
                        in_tree = true;
                        break;
                    }
                }
                if(!in_tree){
                    if(tree._color == white)
                        children = makeNode(board, &move, &tree, black);
                    else
                        children = makeNode(board, &move, &tree, white);
                    tree._childrens.push_back(children);
                }
                tree = selection(children, depth-1);
                return tree;
            }
        }

        Mcts::node_t Mcts::expansion(node_t tree){
            Board board = tree._board;
            if(board.isGameOver())
                return tree;          
            else{
                std::vector<Move> legal_moves = _legal_move->legalMove(board, tree._color);
                //randomiser le legal move
                Move move = legal_moves[0];
                board.doMove(move);
                node_t children;
                if(tree._color == white)
                    children = makeNode(board, &move, &tree, black);
                else
                    children = makeNode(board, &move, &tree, white);
                tree._childrens.push_back(children);
                return children;
            }
        }

        Mcts::node_t Mcts::simulation(node_t tree){
            while(!tree._board.isGameOver()){
                Board board = tree._board;
                std::vector<Move> legal_moves = _legal_move->legalMove(board, tree._color);
                //randomiser le legal move
                Move move = legal_moves[0];
                board.doMove(move);
                node_t children;
                if(tree._color == white)
                    children = makeNode(board, &move, &tree, black);
                else
                    children = makeNode(board, &move, &tree, white);
                tree._childrens.push_back(children);
                tree = children;
            }
            return tree;
        }

        void Mcts::backPropagation(node_t * tree){
            bool victory = tree->_board._pieces[tree->_color]->king.value != 0;
            while(&tree != NULL){
                if(victory)
                    tree->_nb_victory++;
                tree->_nb_exp++;
                tree = tree->_parent;
            }
        }

        Mcts::node_t Mcts::launch(Board& board, int nb_exp, color my_color){
            node_t tree = initialization(board, my_color);
            for(int i=0; i<nb_exp; i++){
                printf("exp %d\n", i);
                node_t select_node = selection(tree, _depth);
                select_node._board.draw();
                node_t deep_node = expansion(select_node);
                node_t leaf = simulation(deep_node);
                backPropagation(&leaf);
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