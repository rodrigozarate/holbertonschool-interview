#include "binary_trees.h"
#include <stdlib.h>


/**
* create_node - creates new node
* @parent: pointer
* @value: int value
* Return: pointer to new node
*/
binary_tree_t *create_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
* avl_helper - define spots of values based on height
* @array: array from which create avl
* @lindex: left index
* @rindex: right index
* @parent: parent if any
* Return: pointer
*/
avl_t *avl_helper(int *array, int lindex, int rindex, avl_t *parent)
{
	avl_t *root = NULL;
	int cindex;

	if (!array)
		return (NULL);

	if (lindex > rindex)
		return (NULL);

	cindex = (lindex + rindex) / 2;
	root = create_node(parent, array[cindex]);
	if (!root)
		return (NULL);

	root->left = avl_helper(array, lindex, cindex - 1, root);
	root->right = avl_helper(array, cindex + 1, rindex, root);

	return (root);
}


/**
* sorted_array_to_avl - convert a sorted array into avl
* @array: int array
* @size: array size
* Return: pointer
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (avl_helper(array, 0, (int)size - 1, NULL));
}
