#include "binary_trees.h"

/**
 * binary_tree_height - size of tree
 * @tree: binary tree to check
 * Return: the size
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	if (height_left >= height_right)
	{
		return (height_left + 1);
	}
	return (height_right + 1);
}

/**
 * binary_tree_depth - Jhony Deep defeat Amber
 * @tree: pointer
 * Return: depth
 */
size_t binary_tree_depth(const heap_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * binary_tree_is_leaf - validate if tree is leaf
 * @node: pointer
 * Return: 0 or 1 if tree is leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * insertnode - Instrerts a node
 * @tree: pointer
 * @level: place
 * @value: value
 * Return: node
 */
binary_tree_t *insertnode(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (binary_tree_depth(tree) == level)
	{
		if (binary_tree_is_leaf(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left = insertnode(tree->left, level, value);
	if (left == NULL)
		right = insertnode(tree->right, level, value);
	else
		return (left);
	return (right);
}

/**
 * heap_insert - inser node in heap
 * @root: double pointer
 * @value: node value
 * Return: new node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t spot, i, tempnodevalue = 0;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}

	spot = binary_tree_height(*root);

	for (i = 0; i <= spot; i++)
	{
		node = (heap_t *)insertnode((binary_tree_t *)*root, i, value);
		if (node != NULL)
			break;
	}

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tempnodevalue = node->parent->n;
		node->parent->n = node->n;
		node->n = tempnodevalue;
		node = node->parent;
	}
	return (node);
}
