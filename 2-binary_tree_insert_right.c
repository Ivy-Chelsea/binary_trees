#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts node at rightchild of another binary tree
 * @parent: A pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 * Return: NULL if error occurs OR pointer to the new node otherwise
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
