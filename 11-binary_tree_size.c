#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to be measured
 *
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;
	size_t size_right = 0, size_left = 0;

	if (tree == NULL)
		return (size);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right != NULL)
		size_right = binary_tree_size(tree->right);
	if (tree->left != NULL)
		size_left = binary_tree_size(tree->left);
	size += (size_right + size_left + 1);
	return (size);
}
