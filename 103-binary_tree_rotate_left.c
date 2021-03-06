#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left-rotation on a binary tree
 * @tree:  pointer to the root node of the tree to rotate
 * Return: NULL or pointer to new root
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *y;

	if (!tree)
		return (NULL);

	y = tree->right;
	tree->right = y->left;
	y->left = tree;
	y->parent = tree->parent;
	tree->parent = y;

	return (y);
}
