#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *result =  NULL;

	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		result = bst_search(tree->left, value);
	else
		result = bst_search(tree->right, value);
	if (result == NULL)
		return (NULL);
	return (result);
}
