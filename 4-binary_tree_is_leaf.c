#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Description: A leaf is a node that does not have any children.
 *              This function checks if the given node is a leaf node.
 *
 * Return: 1 if the node is a leaf
 *         0 if the node is not a leaf or if the node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    return ((!node || node->left || node->right) ? 0 : 1);
}

