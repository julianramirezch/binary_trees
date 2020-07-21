#include "binary_trees.h"

/**
 * check_perfect - check if binary is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: Depth of binary tree
 * @level: level of binary tree
 * Return: 0 if is not perfect
 */

int check_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree->left && !tree->right)
		return (level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (check_perfect(tree->left, depth, level + 1) &&
		check_perfect(tree->right, depth, level + 1));
}


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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: 1 if is perfect.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int level = 0, depth = 0;

	if (!tree)
		return (0);

	if (binary_tree_balance(tree) == 0)
	{
		depth = binary_tree_depth(tree);
		return (check_perfect(tree, depth, level));
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l, r;

	if (!tree)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	return (l - r);
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (!tree)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	if (l > r)
		return (l + 1);

	return (r + 1);
}
