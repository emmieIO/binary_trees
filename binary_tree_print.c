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
 * @s: Buffer size
 *
 * Return: length of printed tree after processing
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int w, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	w = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + w, depth + 1, s);
	for (i = 0; i < w; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < w + right; i++)
			s[depth - 1][offset + left + w / 2 + i] = '-';
		s[depth - 1][offset + left + w / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + w; i++)
			s[depth - 1][offset - w / 2 + i] = '-';
		s[depth - 1][offset + left + w / 2] = '.';
	}
	return (left + w + right);
}

/**
 * _cal_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _cal_height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_r;

	height_left = tree->left ? 1 + _cal_height(tree->left) : 0;
	height_r = tree->right ? 1 + _cal_height(tree->right) : 0;
	return (height_left > height_r ? height_left : height_r);
}

/**
 * binary_tree_printing - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_printing(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _cal_height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
