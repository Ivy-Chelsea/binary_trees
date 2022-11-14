#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary ttree node
 * @parent: Pointer to the parent of the node to create
 * @value: The value to put in the new node
 * Return: NULL if an error occurs OR pointer to the new node otherwise
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
