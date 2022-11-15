#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree
 * @tree: Pointer to the root node of the BST search
 * @value: Value to search for in the BST
 * Return: NULL if valu's not found, pointer to node containing value otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, avlue));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
