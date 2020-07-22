#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: Pinter to ancestor node or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	int depth_a, depth_b;
	binary_tree_t *first_copy, *second_copy;

	if (!first || !second)
		return (NULL);

	depth_a = binary_tree_depth((binary_tree_t *)first);
	depth_b = binary_tree_depth((binary_tree_t *)second);

	if (depth_a == depth_b)
		return ((binary_tree_t *)first->parent);

	first_copy = (binary_tree_t *)first;
	second_copy = (binary_tree_t *)second;

	if (depth_b == depth_a + 1)
	{
		if (second_copy->parent == first_copy)
			return (first_copy);
		if (second_copy->parent->parent == first_copy->parent)
			return (first_copy->parent);
	}

	return (NULL);
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
