#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * 
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 *
 * Description: This function determines if a given node in a binary tree is a leaf.
 *              A leaf is defined as a node that has no children (both left and right
 *              pointers are NULL).
 *
 * Example:
 *              For the following node:
 *                     1
 *                    / \
 *                   2   3
 *              Node 2 and Node 3 are leaves.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);

    if (node->right == NULL && node->left == NULL)
        return (1);
    else
        return (0);
}

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * 
 * @tree: A pointer to the root node of the tree to count the number of leaves.
 *
 * Return: The number of leaves in the tree.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the number of leaves in a binary tree.
 *              A leaf is defined as a node that has no children (both left and right
 *              pointers are NULL). If the tree is NULL, the function returns 0.
 *
 *              The function works by recursively checking each node to see if it
 *              is a leaf and summing the count of leaves from the left and right
 *              subtrees.
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
    if (tree == NULL)
        return (0);
    else
        return (binary_tree_is_leaf(tree) +
                binary_tree_leaves(tree->right) +
                binary_tree_leaves(tree->left));
}

