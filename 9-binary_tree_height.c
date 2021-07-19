#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to be measured
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t height_right = 0, height_left = 0;

	if (tree == NULL)
		return (height);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if (tree->right != NULL)
		height_right = binary_tree_height(tree->right);
	if (tree->left != NULL)
		height_left = binary_tree_height(tree->left);
	height += MAX(height_right, height_left) + 1;
	return (height);
}
