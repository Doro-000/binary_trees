#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			if (tree->parent != NULL)
			{
				if (tree->parent->left  == tree)
					tree->parent->left = NULL;
				else
					tree->parent->right = NULL;
			}
			tree->parent = NULL;
			free(tree);
		}
		else
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
			free(tree);
		}
	}
}
