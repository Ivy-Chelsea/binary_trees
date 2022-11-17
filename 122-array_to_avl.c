#include "binary_tree.h"

/**
 * array_to_avl - Builds an AVL from ana array
 * @array: Pointer to the 1st element of the array to be convrted
 * @size: Number of elements in @array
 * Return: Pointer to the root node of the created AVL on success, NULL otherwise
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0, i < size; i++)
	{
		for (j = 0, j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
