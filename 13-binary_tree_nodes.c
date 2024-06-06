#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * 
 * @tree: A pointer to the root node of the tree to count the nodes from.
 *
 * Return: The number of nodes counted.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the number of nodes in a binary tree
 *              that have at least one child. A node with at least one child is
 *              defined as having at least one non-NULL child pointer.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The number of nodes with at least one child is 2 (Nodes 1 and 2).
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (!tree || (!tree->left && !tree->right))
        return (0);

    return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

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
    if (!tree)
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * 
 * @tree: A pointer to the root node of the tree to count the leaves from.
 *
 * Return: The number of leaves.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the number of leaves in a binary tree.
 *              A leaf is defined as a node that has no children (both left and right
 *              pointers are NULL). If the tree is NULL, the function returns 0.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The number of leaves in the tree is 3 (Nodes 3, 4, and 5).
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

