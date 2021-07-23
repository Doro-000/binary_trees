#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a tree using level-order traversal
 * @tree: root node of the tree to traverse
 * @func: function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL;
	int index = 0, size = 2;

	if (tree != NULL && func != NULL)
	{
		queue = malloc(sizeof(*queue) * size);
		queue[0] = (binary_tree_t *)tree;
		queue[1] = NULL;
		while (queue[index] != NULL)
		{
			if (queue[index]->left != NULL)
			{
				queue = realloc(queue, sizeof(*queue) * (++size));
				queue[size - 1] = NULL;
				queue[size - 2] = queue[index]->left;
			}
			if (queue[index]->right != NULL)
			{
				queue = realloc(queue, sizeof(*queue) * (++size));
				queue[size - 1] = NULL;
				queue[size - 2] = queue[index]->right;
			}
			func(queue[index++]->n);
		}
		free(queue);
	}
}
