#include "binary_trees.h"

/**
 * tree_levelorder - binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @level: level
 * @func:  pointer to a function to call for each node.
 */

void tree_levelorder(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (level == 1)
		func(tree->n);
	if (level > 1)
	{
		tree_levelorder(tree->left, level - 1, func);
		tree_levelorder(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree) + 1;

	for (i = 0; i <= height; i++)
		tree_levelorder(tree, i, func);
}

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


