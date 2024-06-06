#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * 
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the size of a binary tree. The size
 *              of a binary tree is defined as the total number of nodes in the
 *              tree. If the tree is NULL, the function returns 0.
 *
 *              The function works by recursively calculating the size of the
 *              left and right subtrees, adding 1 to account for the current node,
 *              and summing these values.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The size of the tree is 5.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    {
        size_t n_left, n_right;

        n_left = binary_tree_size(tree->left);
        n_right = binary_tree_size(tree->right);
        return (1 + n_left + n_right);
    }
}

