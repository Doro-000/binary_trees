#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: the first node
 * @second: the second node
 *
 * Return:  lowest common ancestor node of the two given nodes
 */
binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t **path = NULL;
	binary_tree_t *ancestor = NULL;
	int x = 0, i, flag = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->parent == NULL || second->parent == NULL)
	{
		if (first->parent == NULL)
			return ((binary_tree_t *)first);
		if (second->parent == NULL)
			return ((binary_tree_t *)second);
	}
	path = malloc(sizeof(*path));
	while (first != NULL)
	{
		path[x++] = (binary_tree_t *)first;
		first = first->parent;
		if (first == NULL)
			break;
		path = realloc(path, sizeof(*path) * (x + 1));
	}
	while (second != NULL)
	{
		for (i = 0; i < x; i++)
		{
			if (second == path[i])
			{
				ancestor = (binary_tree_t *)second;
				free(path);
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
		second = second->parent;
	}
	return (ancestor);
}
