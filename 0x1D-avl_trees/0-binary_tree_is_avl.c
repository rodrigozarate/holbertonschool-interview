#include "binary_trees.h"
#include <limits.h>


/**
 * max_int - finds larger of two int values
 * @a: first value to compare
 * @b: second value to compare
 * Return: larger int value
 */
inline int max_int(int a, int b)
{
	return ((a > b) ? a : b);
}


/**
 * BST_is_AVL_balanced - binary tree balance factor
 * @tree: root node from which to measure
 * Return: height of tree
 */
avl_data_t BST_is_AVL_balanced(const binary_tree_t *tree)
{
	avl_data_t left, right, node;
	int bal_factor;

	if (!tree)
	{
		node.height = -1;
		node.is_AVL = 1;
		return (node);
	}

	left = BST_is_AVL_balanced(tree->left);
	right = BST_is_AVL_balanced(tree->right);

	node.height = 1 + max_int(left.height, right.height);

	bal_factor = right.height - left.height;
	if (bal_factor < -1 || bal_factor > 1)
		node.is_AVL = 0;
	else
		node.is_AVL = left.is_AVL && right.is_AVL;

	return (node);
}


/**
 * tree_is_BST - recursively tests if a binary tree has BST properties
 * @tree: tree to check
 * @prev: pointer
 * Return: 1 if tree is valid BST, or 0 if not or tree is NULL
 */
int tree_is_BST(const binary_tree_t *tree, int *prev)
{
	if (tree)
	{
		if (!tree_is_BST(tree->left, prev))
			return (0);

		if (tree->n <= *prev)
			return (0);

		*prev = tree->n;

		return (tree_is_BST(tree->right, prev));
	}

	return (1);
}


/**
 * binary_tree_is_avl - test if binary tree is a Binary Search Tree
 * @tree: tree to check for AVL
 * Return: 1 if tree is valid AVL, or 0 if not or tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	if (!tree_is_BST(tree, &prev))
		return (0);

	return (BST_is_AVL_balanced(tree).is_AVL);
}
