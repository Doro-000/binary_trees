#include "binary_trees.h"

/**
 * tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: the tree to check
 * @low: lowest node
 * @high: highest node
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int
tree_is_bst(binary_tree_t *tree, binary_tree_t *low, binary_tree_t *high)
{
	int left_less, great_right;
	int left_bst, right_bst;

	if (tree == NULL)
		return (1);

	left_less = (low != NULL && tree->n <= low->n);
	great_right = (high != NULL && tree->n >= high->n);

	if (left_less || great_right)
		return (0);

	left_bst = tree_is_bst(tree->left, low, tree);
	right_bst = tree_is_bst(tree->right, tree, high);
	return (left_bst && right_bst);
}


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
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL || tree->right == NULL)
		return (1);
	if (!tree_is_bst((binary_tree_t *)tree, NULL, NULL))
		return (0);
	left_height = height_n(tree->left);
	right_height = height_n(tree->right);
	if ((left_height - right_height) > 1)
		return (0);
	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
