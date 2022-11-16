#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if the node is a binary tree root
 * @node: A pointer to the node to check
 * Return: -1 if the node is the root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
