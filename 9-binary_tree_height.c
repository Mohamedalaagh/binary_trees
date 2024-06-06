#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * 
 * @tree: A pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree.
 *         If the tree is NULL, returns 0.
 *
 * Description: This function calculates the height of a binary tree. The height
 *              of a tree is defined as the number of edges on the longest path
 *              from the root node to a leaf node. If the tree is NULL, the function
 *              returns 0.
 *
 *              The function works by recursively calculating the height of the
 *              left and right subtrees, adding 1 to account for the current node,
 *              and returning the greater of the two heights.
 *
 * Example:
 *              If the tree is:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              
 *              The height of the tree is 2.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t hel = 0;
    size_t her = 0;

    if (!tree)
        return (0);

    hel = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    her = tree->right ? 1 + binary_tree_height(tree->right) : 0;
    return (hel > her ? hel : her);
}

