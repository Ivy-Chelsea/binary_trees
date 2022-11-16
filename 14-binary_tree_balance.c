#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: 0 if tree is NULL, balance factor otherwise
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures binary tree height
 * @tree: Pointer to the root node of the tree to measure height
 * Return: 0 if tree is NULL, height otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t p = 0, k = 0;

		p = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		k = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((p > k) ? p : k);
	}
	return (0);
}
