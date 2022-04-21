//
// Pdp_chess university project
//

#include "mcts.h"

namespace pdp_chess {


    MCTS::MCTS(Heuristic &heuristic, LegalMove &legalMove, int depth, int nb_exp) : AIPlayer(legalMove, heuristic, depth) {
        _nb_experiment = nb_exp;
    }


    MCTS::node_t MCTS::makeNode(Board &board, Move *move, node_t *parent) {
        node_t tree;
        tree._board = board;
        tree._nb_exp = 0;
        tree._nb_victory = 0;
        tree._move = move;
        tree._parent = parent;
        return tree;
    }

    MCTS::node_t MCTS::initialization(Board &board) {
        node_t tree = makeNode(board, NULL, NULL);
        return tree;
    }

    MCTS::node_t MCTS::selection(node_t tree, int depth, color current_color) {
        Board board = tree._board;
        if (depth <= 0 || board.isGameOver()) {
            return tree;
        } else {
            std::vector<Move> legal_moves = _legal_move->GetLegalMoves(board, current_color);
            //randomiser le legal move
            Move move = legal_moves[0];
            board.doMove(move);
            node_t children = makeNode(board, &move, &tree);
            tree._childrens.push_back(children);
            if (current_color == white)
                selection(children, depth - 1, black);
            else
                selection(children, depth - 1, white);
        }
    }

    MCTS::node_t MCTS::expansion(node_t tree, color current_color) {
        printf("0\n");
        Board board = tree._board;
        if (board.isGameOver())
            return tree;
        else {
            std::vector<Move> legal_moves = _legal_move->GetLegalMoves(board, current_color);
            //randomiser le legal move
            Move move = legal_moves[0];
            board.doMove(move);
            node_t children = makeNode(board, &move, &tree);
            tree._childrens.push_back(children);
            return children;
        }
    }

    MCTS::node_t MCTS::simulation(node_t tree, color current_color) {
        while (!tree._board.isGameOver()) {
            Board board = tree._board;
            std::vector<Move> legal_moves = _legal_move->GetLegalMoves(board, current_color);
            //randomiser le legal move
            Move move = legal_moves[0];
            board.doMove(move);
            node_t children = makeNode(board, &move, &tree);
            tree._childrens.push_back(children);
            tree = children;
        }
        return tree;
    }

    void MCTS::backPropagation(node_t *tree, color my_color) {
        bool victory = tree->_board._pieces[my_color]->king.value != 0;
        while (&tree != NULL) {
            if (victory)
                tree->_nb_victory++;
            tree->_nb_exp++;
            tree = tree->_parent;
        }
    }

    MCTS::node_t MCTS::launch(Board &board, int nb_exp, color my_color) {
        node_t tree = initialization(board);
        for (int i = 0; i < nb_exp; i++) {
            node_t select_node = selection(tree, _depth, my_color);
            printf("1\n");
            node_t deep_node = expansion(select_node, my_color);
            node_t leaf = simulation(deep_node, my_color);
            backPropagation(&leaf, my_color);
        }
        return tree;
    }

    Move MCTS::askNextMove(Board &board, color current_color) {
        node_t tree = launch(board, _nb_experiment, current_color);
        int nb_vitory = 0;
        node_t best_node;
        for (int i = 0; i < tree._childrens.size(); i++) {
            if (tree._childrens[i]._nb_victory >= nb_vitory) {
                best_node = tree._childrens[i];
                nb_vitory = best_node._nb_victory;
            }
        }
        return *(best_node._move);
    }

    std::string MCTS::getParameters() {
        return "";
    }
}