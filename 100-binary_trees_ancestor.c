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
	binary_tree_t *first_copy, *second_copy;

	if (!first || !second)
		return (NULL);

	first_copy = (binary_tree_t *)first;
	second_copy = (binary_tree_t *)second;

	while (first_copy && second_copy)
	{
		if (first_copy == second_copy)
			return (first_copy);
		if (first_copy == second_copy->parent)
			return (first_copy);
		if (first_copy->parent == second_copy->parent->parent)
			return (first_copy->parent);
		first_copy = first_copy->parent;
		second_copy = second_copy->parent;
	}
	return (NULL);
}
