#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find it's ancestor
 * @second: a pointer to the second node to find it's ancestor
 *
 * Return: pointer to the ancestor 
 *         NULL if there is no ancestor 
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_deep, second_deep;

	if (!first || !second)
		return (NULL);

	first_deep = binary_tree_depth(first);
	second_deep = binary_tree_depth(second);

	while (first_deep > second_deep)
	{
		first = first->parent;
		first_deep--;
	}
	while (second_deep > first_deep)
	{
		second = second->parent;
		second_deep--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - calculates the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
