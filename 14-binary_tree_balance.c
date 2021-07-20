#include "binary_trees.h"

/**
 * height_n - measures the height of a binary tree
 * @tree: tree to be measured
 *
 * Return: height of the tree
 */
size_t height_n(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t height_right = 0, height_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right != NULL)
		height_right = height_n(tree->right);
	if (tree->left != NULL)
		height_left = height_n(tree->left);
	height += MAX(height_right, height_left) + 1;
	return (height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree to be used
 *
 * Return: balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_right = 0, height_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if (tree->left != NULL)
		height_left = height_n(tree->left);
	if (tree->right != NULL)
		height_right = height_n(tree->right);
	return (height_left - height_right);
}
