#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * 
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 *         If the tree is NULL, the function returns 0.
 *
 * Description: This function calculates the depth of a given node in a binary tree.
 *              The depth of a node is defined as the number of edges from the node
 *              to the tree's root node. The root node has a depth of 0.
 *              If the tree is NULL, the function returns 0.
 *
 *              The function works by recursively traversing from the given node
 *              up to the root node, counting the edges.
 *
 * Example:
 *              For the following tree:
 *                     1
 *                    / \
 *                   2   3
 *                  / \
 *                 4   5
 *              The depth of node 4 is 2.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree == NULL || tree->parent == NULL)
        return (0);
    else
        return (1 + binary_tree_depth(tree->parent));
}

