#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds uncle node in a binary tree
 * @node: Pointer to the node to find the uncle of
 * Return: NULL if node's NULL or has no uncle, pointer to uncle node otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
