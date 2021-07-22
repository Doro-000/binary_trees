#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right-rotation on a binary tree
 * @tree: tree to be rotated
 *
 * Return: new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *temp_2 = NULL;

	if (tree == NULL)
		return (NULL);
	if (tree->left != NULL)
	{
		temp = tree;
		tree = tree->left;
		temp_2 = tree->right;
		tree->right = temp;
		tree->right->left = temp_2;
		if (tree->right->left != NULL)
			tree->right->left->parent = tree->right;
		tree->parent = temp->parent;
		tree->right->parent = tree;
		return (tree);
	}
	return (NULL);
}
