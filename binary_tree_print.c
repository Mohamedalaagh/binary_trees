#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, x;

    if (!tree)
        return (0);
    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);
    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);
    for (x = 0; x < width; x++)
        s[depth][offset + left + x] = b[x];
    if (depth && is_left)
    {
        for (x = 0; x < width + right; x++)
            s[depth - 1][offset + left + width / 2 + x] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (x = 0; x < left + width; x++)
            s[depth - 1][offset - width / 2 + x] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
    size_t height_l;
    size_t height_r;

    height_l = tree->left ? 1 + _height(tree->left) : 0;
    height_r = tree->right ? 1 + _height(tree->right) : 0;
    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 *
 * Description:
 * This function prints a binary tree in a 2D diagram form, where each level
 * of the tree is represented as a line in the output. The tree structure
 * is printed with connecting lines between parent and child nodes.
 * The function handles memory allocation for the buffer used to store the
 * printed tree representation. If the tree is empty or memory allocation
 * fails, the function does not print anything.
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, x, j;

    if (!tree)
        return;
    height = _height(tree);
    s = malloc(sizeof(*s) * (height + 1));
    if (!s)
        return;
    for (x = 0; x < height + 1; x++)
    {
        s[x] = malloc(sizeof(**s) * 255);
        if (!s[x])
            return;
        memset(s[x], 32, 255);
    }
    print_t(tree, 0, 0, s);
    for (x = 0; x < height + 1; x++)
    {
        for (j = 254; j > 1; --j)
        {
            if (s[x][j] != ' ')
                break;
            s[x][j] = '\0';
        }
        printf("%s\n", s[x]);
        free(s[x]);
    }
    free(s);
}

