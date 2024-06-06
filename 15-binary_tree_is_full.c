#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * 
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function determines if a binary tree is full. A full binary
 *              tree is defined as a tree in which every node has either 0 or 2
 *              children. If a node has only one child, the tree is not considered
 *              full. The function recursively checks each node to see if it meets
 *              this condition.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The tree is full because every node has either 0 or 2 children.
 *
 *              For the following tree:
 *                     1
 *                    / 
 *                   2   
 *                  / \
 *                 4   5
 *              The tree is not full because the root node has only one child.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!tree->right && !tree->left)
        return (1);

    if (tree->right && tree->left)
        return (binary_tree_is_full(tree->left) &&
                binary_tree_is_full(tree->right));

    return (0);
}

