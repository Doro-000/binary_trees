#include "binary_trees.h"

/**
 * height_ - measures the height of a binary tree
 * @tree: tree to be measured
 *
 * Return: height of the tree
 */
size_t height_(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t height_right = 0, height_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right != NULL)
		height_right = height_(tree->right);
	if (tree->left != NULL)
		height_left = height_(tree->left);
	height += MAX(height_right, height_left) + 1;
	return (height);
}

/**
 * balance_factor - measures the balance factor of a binary tree
 * @tree: tree to be used
 *
 * Return: balance factor of the tree
 */
int balance_factor(const binary_tree_t *tree)
{
	size_t height_right = 0, height_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if (tree->left != NULL)
		height_left = height_(tree->left);
	if (tree->right != NULL)
		height_right = height_(tree->right);
	return (height_left - height_right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to be checked
 *
 * Return: 1 for true, 0 for false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect_right = 0, perfect_left = 0;
	int tree_balance = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	tree_balance = balance_factor(tree);
	perfect_right = binary_tree_is_perfect(tree->right);
	perfect_left = binary_tree_is_perfect(tree->left);
	if (tree_balance == 0 && perfect_right == 1 && perfect_left == 1)
		return (1);
	else
		return (0);
}
