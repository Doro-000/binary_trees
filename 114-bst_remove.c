#include "binary_trees.h"

/**
 * search - searches for a value in a Binary Search Tree
 * @tree: root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value
 */
bst_t *search(const bst_t *tree, int value)
{
	bst_t *result =  NULL;

	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		result = search(tree->left, value);
	else
		result = search(tree->right, value);
	if (result == NULL)
		return (NULL);
	return (result);
}

/**
 * min - finds the minumum node in bst
 * @root: root of tree to be searched
 *
 * Return: minumum node
 */
bst_t *min(const bst_t *root)
{
	if (root == NULL)
		return (NULL);
	while (root->left != NULL)
		root = root->left;
	return ((bst_t *)root);
}

/**
 * get_successor - Get the in-order successor of a node 
 * @node: node to find successor for
 * @root: root of tree
 *
 * Return: successor of the node
 */
bst_t *get_successor(const bst_t *node, const bst_t *root)
{
	bst_t *current = (bst_t *)root;
	bst_t *successor = NULL;

	if (root == NULL)
		return (NULL);
	while (current->n != node->n)
	{
		if (current->n > node->n)
		{
			successor = current;
			current = current->left;
		}
		else
			current = current->right;
	}
	if (current != NULL && current->right != NULL)
		successor = min(current->right);
	return (successor);
}

/**
 * del_leaf - deletes a leaf from a tree
 * @node: node to delete
 * @root: root of the tree
 *
 * Return: the new tree
 */
bst_t *del_leaf(bst_t **node, bst_t *root)
{
	if ((*node)->parent != NULL)
	{
		if ((*node)->parent->right == *node)
			(*node)->parent->right = NULL;
		else
			(*node)->parent->left = NULL;
		(*node)->parent = NULL;
		free(*node);
		return (root);
	}
	else
	{
		free(*node);
		return (NULL);
	}
}

/**
 * bst_remove - removes a node from a Binary Search Tree 
 * @root: root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;
	bst_t *successor = NULL;
	bst_t *temp = NULL;

	node = search(root, value);
	if (node == NULL)
		return (NULL);

	if (node->right == NULL && node->left == NULL)
		return (del_leaf(&node, root));

	else if (node->right == NULL || node->left == NULL)
	{
		if (node->right == NULL)
		{
			node->n = node->left->n;
			temp = node->left;
			node->left = NULL;
		}
		else
		{
			node->n = node->right->n;
			temp = node->right;
			node->left = NULL;
		}
		free(temp);
		return(root);
	}
	else
	{
		successor = get_successor(node, root);
		node->n = successor->n;
		if (successor->parent->right == successor)
			successor->parent->right = NULL;
		else
			successor->parent->left = NULL;
		free(successor);
		return (root);
	}
}
