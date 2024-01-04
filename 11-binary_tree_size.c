#include "binary_trees.h"

/**
 * binary_tree_size - calculate the size of a binary tree
 * @tree: tree to measure it's the size
 *
 * Return: size of the tree
 *         0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
