#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap from an array
 * @array: Pointer to the 1st element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to created Binary Heap root on success, NULL otherwise
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
