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
	bst_t *new_root = NULL;

	node = search(root, value);
	if (node == NULL)
		return (NULL);

	if (node->right == NULL || node->left == NULL)
	{
		if (node->parent != NULL)
		{
			if (node->parent->right == node)
			{
				if (node->right != NULL)
				{
					node->right->parent = node->parent;
					node->parent->right = node->right;
				}
				else if (node->left != NULL)
				{
					node->left->parent = node->parent;
					node->parent->right = node->left;
				}
				else
					node->parent->right = NULL;
			}
			else
			{
				if (node->right != NULL)
				{
					node->right->parent = node->parent;
					node->parent->left = node->right;
				}
				else if (node->left != NULL)
				{
					node->left->parent = node->parent;
					node->parent->left = node->left;
				}
				else
					node->parent->left = NULL;
			}
			node->parent = NULL;
			free(node);
			return (root);
		}
		else
		{
			free(node);
			return (NULL);
		}
	}
	successor = get_successor(node, root);
	if (successor->parent->right == successor)
		successor->parent->right = NULL;
	else
		successor->parent->left = NULL;
	temp = node;
	node = successor;
	node->parent = temp->parent;
	node->right = temp->right;
	node->right->parent = node;
	node->left = temp->left;
	node->left->parent = node;
	if (temp->parent != NULL)
	{
		if (temp->parent->right == temp)
			temp->parent->right = node;
		else
			temp->parent->left = node;
	}
	free(temp);	
	new_root = node;
	while (new_root->parent != NULL)
		new_root = new_root->parent;
	return (new_root);
}
