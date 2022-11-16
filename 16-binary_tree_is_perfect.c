#include "binary_trees.h"

/**
 * is_leaf - Checks if a node is a leaf of abinary tree
 * @node: Pointer to the node to check
 * Return: 1 if the node is a leaf, 0 othrwise
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns depth of a given node in a binary tree
 * @tree: Pointer to the node to measure depth of
 * Return: The depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree
 * @tree: Pointer to the root node of the tree to find leaf in
 * Return: Pointer to the first leaf encountered
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks ia a binary tree is perfect recursibvely
 * @tree: Pointer to the root node of the tree to check
 * @leaf_depth: Depth of one leaf in the binary tree
 * @level: Level of current node
 * Return: 1 if it's the perfect tree, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree,
			 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or not perfect, 1 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
