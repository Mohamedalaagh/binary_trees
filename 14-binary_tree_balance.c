#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree for balancing purposes.
 * 
 * @tree: A pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the height of a binary tree. The height
 *              of a tree is defined as the number of edges on the longest path
 *              from the root node to a leaf node. This function is specifically
 *              used for balancing purposes, and it treats NULL subtrees as having
 *              a height of 1.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The height of the tree is 3.
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
    size_t i = 0;
    size_t j = 0;

    if (tree == NULL)
    {
        return (0);
    }
    else
    {
        if (tree)
        {
            i = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
            j = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
        }
        return ((i > j) ? i : j);
    }
}

#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor of.
 *
 * Return: The balance factor of the tree.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the balance factor of a binary tree. The
 *              balance factor is defined as the difference between the heights
 *              of the left and right subtrees. A balance factor of 0 indicates
 *              that the tree is perfectly balanced, a positive balance factor
 *              indicates that the left subtree is taller, and a negative balance
 *              factor indicates that the right subtree is taller.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The balance factor of the tree is 1 (left height - right height = 3 - 2 = 1).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int l = 0, r = 0, t = 0;

    if (tree)
    {
        l = ((int)binary_tree_height_b(tree->left));
        r = ((int)binary_tree_height_b(tree->right));
        t = l - r;
    }
    return (t);
}

