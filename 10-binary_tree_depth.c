#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the binary tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *aux;
	size_t depth = 0;

	if (!tree)
		return (0);

	aux = tree;
	while (aux->parent)
	{
		aux = aux->parent;
		depth += 1;
	}

	return (depth);
}
