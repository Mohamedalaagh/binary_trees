#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal
 *                         and applies a function to each node's value.
 * 
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The function
 *        takes an integer parameter which is the value of the node.
 *
 * Description: This function performs a post-order traversal on a binary tree.
 *              In post-order traversal, the function first recursively visits the
 *              left subtree, then recursively visits the right subtree, and finally
 *              visits the root node. For each node visited, the provided function
 *              `func` is called with the node's value.
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
 *              the output will be: 4 5 2 3 1
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    binary_tree_postorder(tree->left, func);
    binary_tree_postorder(tree->right, func);
    func(tree->n);
}

