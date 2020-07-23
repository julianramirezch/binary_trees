#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right-rotation on a binary tree
 * @tree:  pointer to the root node of the tree to rotate
 * Return: NULL or pointer to new root
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *y;

	if (!tree)
		return (NULL);

	y = tree->left;
	tree->left = y->right;
	y->right = tree;
	y->parent = tree->parent;
	tree->parent = y;

	return (y);
}
