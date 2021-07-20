#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: tree to be used
 *
 * Return: the number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;
	size_t nodes_right = 0, nodes_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
	{
		if (tree->parent == NULL)
			return (1);
		else
			return (0);
	}
	if (tree->right != NULL)
		nodes_right = binary_tree_nodes(tree->right);
	if (tree->left != NULL)
		nodes_left = binary_tree_nodes(tree->left);
	nodes += (nodes_left + nodes_right + 1);
	return (nodes);
}