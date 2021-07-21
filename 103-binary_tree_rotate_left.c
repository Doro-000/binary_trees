#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left-rotation on a binary tree
 * @tree: tree to be rotated
 *
 * Return: new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *temp_2 = NULL;

	if (tree == NULL)
		return (NULL);
	if (tree->right != NULL)
	{
		temp = tree;
		tree = tree->right;
		temp_2 = tree->left;
		tree->left = temp;
		tree->left->right = temp_2;
		tree->parent = NULL;
		tree->left->parent = tree;
		return (tree);
	}
	return (NULL);
}
