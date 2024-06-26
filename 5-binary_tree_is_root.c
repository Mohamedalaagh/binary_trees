#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 * @node: pointer to the node to check
 *
 * Description: A root node is a node that does not have a parent.
 *              This function checks if the given node is a root node.
 *
 * Return: 1 if the node is a root
 *         0 if the node is not a root or if the node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    return ((!node || node->parent) ? 0 : 1);
}

