#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_tree_ancestor - Finds lowest common ancestor of two nodes
 * @first: Pointer to 1st node
 * @second: Pointer to 2nd node
 * Return: NULL if no common ancestors, common ancestor otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (firs == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;

	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - Measures depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: 0 if tree is NULL, else the depth
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
