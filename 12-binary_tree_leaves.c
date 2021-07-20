#include "binary_trees.h"


/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree to be used
 *
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;
	size_t leaves_right = 0, leaves_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right != NULL)
		leaves_right = binary_tree_leaves(tree->right);
	if (tree->left != NULL)
		leaves_left = binary_tree_leaves(tree->left);
	leaves += (leaves_right + leaves_left);
	return (leaves);
}
