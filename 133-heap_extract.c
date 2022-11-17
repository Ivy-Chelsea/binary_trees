#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of the tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height on success, 0 if tree is NUL
 */
size_t tree_height(const heap_t *tree)
{
	size_ height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);



	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);

}
/**
 * tree_size_h - Measures sum of heights of a binary tree
 * @tree: Pointer to root node of tree to measure
 * Return: Height on success, 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		
