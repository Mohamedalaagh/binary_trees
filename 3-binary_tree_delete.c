#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 *
 * Description: This function recursively deletes all nodes in a binary tree.
 * If the tree is NULL, the function does nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;
    binary_tree_delete(tree->right);
    binary_tree_delete(tree->left);
    free(tree);
}

