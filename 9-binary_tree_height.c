#include "binary_trees.h"

/**
 * binary_tree_height - Measures the binary tree height
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: 0 f tree is null, else heght
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t p = 0, k = 0;

		p = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		k = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((p > k) ? p : k);
	}
	return (0);
}
