#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: array to be converted
 * @size: number of element in the array
 *
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *new_tree = NULL;
	bst_t *node = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		node = bst_insert(&new_tree, array[i]);
		if (node == NULL)
			continue;
	}
	return (new_tree);
}
