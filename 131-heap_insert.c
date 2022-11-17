#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root ode of the heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to created node on success, NULL otherwise
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverse tree to 1st empty slot based on the binary
	 * representation of the number of leaves
	 * Example
	 * If there are 12 nodes in a complete tree, there are 5 leaves on
	 * the 4th tier of the tree. 5 is 101 binary. 1 corresponds to 
	 * right, 0 to left
	 * The 1st empty node is 101 == RLR, *root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	/* Flip value with parent until parent avlue exceeds new value */

	return (new);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure the size
 * Return: 0 if tree is NULL, tree size Otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
