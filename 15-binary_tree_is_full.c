#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: tree to be checked
 *
 * Return: 1 for true, 0 for false
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full_right, full_left;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	full_right = binary_tree_is_full(tree->left);
	full_left = binary_tree_is_full(tree->right);
	if (full_right && full_left)
		return (1);
	else
		return (0);
}
