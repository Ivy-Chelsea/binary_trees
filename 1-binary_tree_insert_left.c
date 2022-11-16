#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as leftchild of another binary tree
 * @parent: A pointer to the node to insert the left-child
 * @value: The valuue to store in the new node
 * Return: NULL on error, pointer to the new node otherwise
 * If parent has a left-chiold, the new node takes it's place & the old
 * left-child is set as the left-child of the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
