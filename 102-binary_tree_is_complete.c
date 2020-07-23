#include "binary_trees.h"

/**
 * is_complete - checks if a binary tree is complete
 * @nodes: number of nodes
 * @tree: pointer to the root node of the tree to check
 * @idx: index
 * Return: 0 or 1
 */

int is_complete(const binary_tree_t *tree, int nodes, int idx)
{
	if (!tree)
		return (1);
	if (idx >= nodes)
		return (0);

	return (is_complete(tree->left, nodes, 2 * idx + 1) &&
		is_complete(tree->right, nodes, 2 * idx + 2));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes;

	if (!tree)
		return (0);

	nodes = binary_tree_size(tree);

	return (is_complete(tree, nodes, 0));
}

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree:  pointer to the root node of the tree to measure the size
 * Return: Size of binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else
		return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
