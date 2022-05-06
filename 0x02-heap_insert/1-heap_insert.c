#include binary_trees.h

/**
 * binary_tree_size - size of tree
 * @tree: binary tree to check
 * Return: the size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left, size_right;

	if (tree == NULL)
		return (0);

	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);

	return (size_left + size_right + 1);
}
/**
 * heap_insert - inser node in heap
 * @root: double pointer
 * @value: node value
 * Return: new node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	/* if adress is null make root */
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	/* check for place to put the node according to MAX heap */
	while (node->parent != NULL && node->n > node->parent->n)
	{
		tempnodevalue = node->parent->n;
		node->parent->n = node->n;
		node->n = tempnodevalue;
		node = node->parent;
	}
	/* validate if node must be swaped */
	/* validate if node is leaf */
	/* return new node */
	return (*newnode);
}
