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
 * binary_tree_is_bst - wrapper function for tree_is_bst
 * @tree: tree to be checked
 *
 * Return: 1 for true, 0 for false
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_is_bst((binary_tree_t *)tree, NULL, NULL));
}
