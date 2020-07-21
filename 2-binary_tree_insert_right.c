#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value:  value to store in the new node
 * Return: value to store in the new node or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (parent == NULL)
		return (NULL);

	right_node = malloc(sizeof(binary_tree_t));
	if (!right_node)
		return (NULL);
	right_node->n = value;

	if (parent->right == NULL)
	{
		right_node->parent = parent;
		right_node->left = NULL;
		right_node->right = NULL;
		parent->right = right_node;
	}
	else
	{
		right_node->right = parent->right;
		parent->right->parent = right_node;
		right_node->parent = parent;
		right_node->left = NULL;
		parent->right = right_node;
	}

	return (right_node);
}
