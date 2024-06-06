#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using in-order traversal
 *                       and applies a function to each node's value.
 * 
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The function
 *        takes an integer parameter which is the value of the node.
 *
 * Description: This function performs an in-order traversal on a binary tree.
 *              In in-order traversal, the function first recursively visits the
 *              left subtree, then visits the root node, and finally recursively
 *              visits the right subtree. For each node visited, the provided
 *              function `func` is called with the node's value.
 *
 *              If the `tree` pointer is NULL, or the `func` pointer is NULL,
 *              the function does nothing.
 *
 * Example:
 *              If the tree is:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              
 *              And the `func` is a function that prints the node value,
 *              the output will be: 4 2 5 1 3
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    binary_tree_inorder(tree->left, func);
    func(tree->n);
    binary_tree_inorder(tree->right, func);
}

