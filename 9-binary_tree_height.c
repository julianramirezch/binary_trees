#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	if (l > r)
		return (l + 1);

	return (r + 1);
}
